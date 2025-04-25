// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Bloque.h"
#include "BloqueCesped.generated.h"

/**
 * 
 */
UCLASS()
class BOMBERMAN_012025_API ABloqueCesped : public ABloque
{
	GENERATED_BODY()

public:
	//Constructor
	ABloqueCesped();

	virtual void Tick(float DeltaTime) override;

protected:

	virtual void BeginPlay() override;

private:

	FVector PosicionInicial;

};
