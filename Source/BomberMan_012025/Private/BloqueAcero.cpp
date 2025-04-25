// Fill out your copyright notice in the Description page of Project Settings.


#include "BloqueAcero.h"

ABloqueAcero::ABloqueAcero()
{
	if (MallaBloque)
	{
		static ConstructorHelpers::FObjectFinder<UMaterial> MallaBase(TEXT("/Script/Engine.Material'/Game/StarterContent/Materials/M_Metal_Chrome.M_Metal_Chrome'"));
		if (MallaBase.Succeeded())
		{
			MallaBloque->SetMaterial(0, MallaBase.Object); // establece la malla del bloque
		}
	}
	PuedeMoverse = false; // el bloque no puede moverse
}

void ABloqueAcero::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABloqueAcero::BeginPlay()
{
	Super::BeginPlay();
	PosicionInicial = GetActorLocation(); // guarda la posicion inicial del bloque
	FloatSpeed = 0.0f; // velocidad de movimiento
	RotationSpeed = 0.0f; // velocidad de rotacion
}
