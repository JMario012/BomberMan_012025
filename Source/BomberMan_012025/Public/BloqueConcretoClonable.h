#pragma once

#include "CoreMinimal.h"
#include "Bloque.h"
#include "IBloquePrototipo.h"
#include "BloqueConcretoClonable.generated.h"

UCLASS()
class BOMBERMAN_012025_API ABloqueConcretoClonable : public ABloque, public IBloquePrototipo
{
    GENERATED_BODY()

public:
    virtual ABloque* Clonar(UWorld* World, const FVector& Posicion) override;
};