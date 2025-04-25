// Copyright Epic Games, Inc. All Rights Reserved.

#include "BomberMan_012025GameMode.h"
#include "BomberMan_012025Character.h"
#include "UObject/ConstructorHelpers.h"
#include "Bloque.h"
#include "BloqueAcero.h"
#include "BloqueCesped.h"
#include "BloqueConcreto.h"
#include "BloqueLadrillo.h"
#include "BloqueMadera.h"
#include <Kismet/GameplayStatics.h>

ABomberMan_012025GameMode::ABomberMan_012025GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ABomberMan_012025GameMode::BeginPlay()
{
	GEngine->AddOnScreenDebugMessage(-1, -1, FColor::Red, TEXT("Bloque Spawning"));

	// Recorremos la matriz para generar los bloques
	for (int32 fila = 0; fila < aMapaBloques.Num(); ++fila)
	{
		for (int32 columna = 0; columna < aMapaBloques[fila].Num(); ++columna)
		{
			int32 valor = aMapaBloques[fila][columna];
			if (valor != 0) // Si no es espacio vacío
			{
				// Calculamos la posición del bloque
				FVector posicionBloque = FVector(
					XInicialBloque + columna * AnchoBloque,
					YInicialBloque + fila * LargoBloque,
					0.0f); // Z queda en 0 (altura del bloque)

				// Llamamos a la función para generar un bloque
				SpawnBloques(posicionBloque, valor);
			}
		}
	}
	ColocarBombermanEnBloqueDeBorde();
}

void ABomberMan_012025GameMode::SpawnBloques(FVector posicion, int32 tipoBloque)
{
	ABloque* BloqueGenerado = nullptr;
	// Crear el bloque dependiendo del tipo
	if (tipoBloque == 5)
	{
		BloqueGenerado = GetWorld()->SpawnActor<ABloqueAcero>(ABloqueAcero::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));
	}
	else if (tipoBloque == 4)
	{
		BloqueGenerado = GetWorld()->SpawnActor<ABloqueMadera>(ABloqueMadera::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));
	}
	else if (tipoBloque == 3)
	{
		BloqueGenerado = GetWorld()->SpawnActor<ABloqueCesped>(ABloqueCesped::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));
	}
	else if (tipoBloque == 2)
	{
		BloqueGenerado = GetWorld()->SpawnActor<ABloqueLadrillo>(ABloqueLadrillo::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));
	}
	else if (tipoBloque == 1)
	{
		BloqueGenerado = GetWorld()->SpawnActor<ABloqueConcreto>(ABloqueConcreto::StaticClass(), posicion, FRotator(0.0f, 0.0f, 0.0f));
	}
	else {
		return;
	}
	// Agregar el bloque a la lista de bloques generados por el TArray
	if (BloqueGenerado)
	{
		aBloques.Add(BloqueGenerado);
	}
}

void ABomberMan_012025GameMode::ColocarBombermanEnBloqueDeBorde()
{
	TArray<TTuple<FIntPoint, int32>> BloquesCandidatos;

	int32 Filas = aMapaBloques.Num();
	int32 Columnas = aMapaBloques[0].Num();

	for (int32 fila = 0; fila < Filas; ++fila)
	{
		for (int32 columna = 0; columna < Columnas; ++columna)
		{
			if (aMapaBloques[fila][columna] == 4) // Solo bloques de madera
			{
				int32 MaderaCercana = 0;

				// Revisamos los 8 vecinos
				for (int32 df = -1; df <= 1; ++df)
				{
					for (int32 dc = -1; dc <= 1; ++dc)
					{
						if (df == 0 && dc == 0) continue;

						int32 nf = fila + df;
						int32 nc = columna + dc;

						if (nf >= 0 && nf < Filas && nc >= 0 && nc < Columnas)
						{
							if (aMapaBloques[nf][nc] == 4)
							{
								MaderaCercana++;
							}
						}
					}
				}

				BloquesCandidatos.Add(TTuple<FIntPoint, int32>(FIntPoint(fila, columna), MaderaCercana));
			}
		}
	}

	if (BloquesCandidatos.Num() > 0)
	{
		// Ordenamos para obtener los de mayor acumulación
		BloquesCandidatos.Sort([](const TTuple<FIntPoint, int32>& A, const TTuple<FIntPoint, int32>& B) {
			return A.Value > B.Value;
			});

		int32 MaxMadera = BloquesCandidatos[0].Value;

		TArray<FIntPoint> MejoresCandidatos;
		for (const auto& Candidato : BloquesCandidatos)
		{
			if (Candidato.Value == MaxMadera)
			{
				MejoresCandidatos.Add(Candidato.Key);
			}
			else
			{
				break;
			}
		}

		// Elegimos aleatoriamente uno de los mejores
		FIntPoint Seleccionado = MejoresCandidatos[FMath::RandRange(0, MejoresCandidatos.Num() - 1)];

		FVector Posicion = ObtenerPosicionMundoDesdeGrid(Seleccionado.X, Seleccionado.Y);

		// Ajustamos la altura para que el personaje aparezca encima del bloque
		float AlturaBloque = 200.f; // Ajustalo si tus bloques tienen otra altura

		if (ACharacter* Personaje = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0))
		{
			Personaje->SetActorLocation(Posicion + FVector(0, 0, AlturaBloque));
		}

	
	}
}

FVector ABomberMan_012025GameMode::ObtenerPosicionMundoDesdeGrid(int32 fila, int32 columna)
{
	return FVector(
		XInicialBloque + columna * AnchoBloque,
		YInicialBloque + fila * LargoBloque,
		0.0f // Z base
	);
}
