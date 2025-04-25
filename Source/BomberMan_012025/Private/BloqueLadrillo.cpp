// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueLadrillo.h"

ABloqueLadrillo::ABloqueLadrillo()
{
	if (MallaBloque)
	{
		static ConstructorHelpers::FObjectFinder<UMaterial> MallaBase(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Brick_Clay_Old.M_Brick_Clay_Old'"));
		if (MallaBase.Succeeded())
		{
			MallaBloque->SetMaterial(0, MallaBase.Object); // establece la malla del bloque
		}
	}
	//PuedeMoverse = FMath::RandBool; // el bloque no puede moverse, o puede moverse aleatoriamente, o solo se mueve
}

void ABloqueLadrillo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// No hay lógica de movimiento o rotación para el bloque de ladrillo
	// Puedes agregar lógica aquí si es necesario
	// Por ejemplo, puedes hacer que el bloque se mueva o rote en función de la posición inicial
	// FVector NuevaPosicion = PosicionInicial + FVector(0.0f, 0.0f, FloatSpeed * DeltaTime);
	// SetActorLocation(NuevaPosicion);
	// FRotator NuevaRotacion = FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f);
	// AddActorLocalRotation(NuevaRotacion);
}

void ABloqueLadrillo::BeginPlay()
{
	Super::BeginPlay();
	PosicionInicial = GetActorLocation(); // guarda la posicion inicial del bloque
	FloatSpeed = 0.0f; // velocidad de movimiento
	RotationSpeed = 0.0f; // velocidad de rotacion
}
