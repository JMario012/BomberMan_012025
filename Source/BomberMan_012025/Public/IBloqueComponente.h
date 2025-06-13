#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "IBloqueComponente.generated.h"

UINTERFACE(MinimalAPI)
class UIBloqueComponente : public UInterface
{
    GENERATED_BODY()
};

class IBloqueComponente
{
    GENERATED_BODY()

public:
    virtual void Destruir() = 0;
};
