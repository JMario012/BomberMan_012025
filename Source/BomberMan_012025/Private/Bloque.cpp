// Fill out your copyright notice in the Description page of Project Settings.


#include "Bloque.h"

// Sets default values
ABloque::ABloque()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MallaBloque = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MallaBloque"));// crea la malla del bloque
	RootComponent = MallaBloque; // establece la malla como el componente raíz

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MallaBase(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	if (MallaBase.Succeeded())
	{
		MallaBloque->SetStaticMesh(MallaBase.Object); // establece la malla del bloque
		MallaBloque->SetRelativeScale3D(FVector(1.0f, 1.0f, 2.0f)); // establece la escala del bloque
		MallaBloque->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f)); 
	}
	PuedeMoverse = false;
}

// Called when the game starts or when spawned
void ABloque::BeginPlay()
{
	Super::BeginPlay();
	PosicionInicial = GetActorLocation();
	TiempoTranscurrido = 0.0f;

}

// Called every frame
void ABloque::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (PuedeMoverse)
	{
		TiempoTranscurrido += DeltaTime;
		float DesplazamientoZ = FMath::Sin(TiempoTranscurrido * VelocidadMovimiento) * AmplitudMovimiento;

		FVector NuevaPosicion = PosicionInicial;
		NuevaPosicion.Z += DesplazamientoZ;

		SetActorLocation(NuevaPosicion);
	}
}

void ABloque::AplicarComportamientoGrupal()
{
	// Aquí defines lo que significa que sea "destructible"
	// Por ejemplo, puedes poner una bandera o lógica personalizada
	UE_LOG(LogTemp, Warning, TEXT("Bloque marcado como destructible (comportamiento grupal)"));
}

