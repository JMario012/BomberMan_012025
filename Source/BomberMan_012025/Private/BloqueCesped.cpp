// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueCesped.h"

ABloqueCesped::ABloqueCesped()
{
	if (MallaBloque)
	{
		static ConstructorHelpers::FObjectFinder<UMaterial> MallaBase(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Ground_Grass.M_Ground_Grass'"));
		if (MallaBase.Succeeded())
		{
			MallaBloque->SetMaterial(0, MallaBase.Object); // establece la malla del bloque
		}
	}
	//PuedeMoverse = FMath::RandBool; // el bloque no puede moverse, o puede moverse aleatoriamente, o solo se mueve
}

void ABloqueCesped::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// No hay lógica de movimiento o rotación para el bloque de césped
}

void ABloqueCesped::BeginPlay()
{
	Super::BeginPlay();
	PosicionInicial = GetActorLocation(); // guarda la posicion inicial del bloque
	FloatSpeed = 0.0f; // velocidad de movimiento
	RotationSpeed = 0.0f; // velocidad de rotacion
}
