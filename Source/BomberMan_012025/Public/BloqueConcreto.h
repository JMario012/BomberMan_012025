// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bloque.h"
#include "BloqueConcreto.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API ABloqueConcreto : public ABloque
{
	GENERATED_BODY()
	
public:
	// Constructor
	ABloqueConcreto();

	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:
	FVector PosicionInicial; // guarda la posicion inicial del bloque

};
