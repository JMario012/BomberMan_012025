// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TipoBloque.generated.h"
/**
 * 
 */
UENUM(BlueprintType)
enum class ETipoBloque : uint8
{
    Cesped = 1     UMETA(DisplayName = "Césped"),
    Madera = 2     UMETA(DisplayName = "Madera"),
    Ladrillo = 3     UMETA(DisplayName = "Ladrillo"),
    Concreto = 4     UMETA(DisplayName = "Concreto"),
    Acero = 5     UMETA(DisplayName = "Acero")
};
