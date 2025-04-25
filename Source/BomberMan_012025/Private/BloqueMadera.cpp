// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueMadera.h"

ABloqueMadera::ABloqueMadera()
{
	if (MallaBloque)
	{
		static ConstructorHelpers::FObjectFinder<UMaterial> MallaBase(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Wood_Floor_Walnut_Polished.M_Wood_Floor_Walnut_Polished'"));
		if (MallaBase.Succeeded())
		{
			MallaBloque->SetMaterial(0, MallaBase.Object); // establece la malla del bloque
		}
	}
	//PuedeMoverse = FMath::RandBool; // el bloque no puede moverse, o puede moverse aleatoriamente, o solo se mueve
}

void ABloqueMadera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABloqueMadera::BeginPlay()
{
	Super::BeginPlay();
	PosicionInicial = GetActorLocation(); // guarda la posicion inicial del bloque
	FloatSpeed = 0.0f; // velocidad de movimiento
	RotationSpeed = 0.0f; // velocidad de rotacion
}
