// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Bloque.generated.h"

UCLASS()
class BOMBERMAN_012025_API ABloque : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	ABloque();

protected:
	// la malla del bloque
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bloque")
	UStaticMeshComponent* MallaBloque;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float FloatSpeed;
	float RotationSpeed;

public:
	// Velocidad y amplitud del movimiento vertical
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movimiento")
	float AmplitudMovimiento = 50.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movimiento")
	float VelocidadMovimiento = 2.0f;

	// Activar o desactivar el movimiento
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movimiento")
	bool PuedeMoverse;

private:
	FVector PosicionInicial;
	float TiempoTranscurrido;

};
