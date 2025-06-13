#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IBloquePrototipo.generated.h"

UINTERFACE(MinimalAPI)
class UIBloquePrototipo : public UInterface
{
    GENERATED_BODY()
};

class IBloquePrototipo
{
    GENERATED_BODY()

public:
    virtual class ABloque* Clonar(UWorld* World, const FVector& Posicion) = 0;
};
