#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IBloqueComponente.h"
#include "GrupoBloques.generated.h"

UCLASS()
class BOMBERMAN_012025_API AGrupoBloques : public AActor, public IBloqueComponente
{
    GENERATED_BODY()

public:
    AGrupoBloques();

    UFUNCTION()
    void AgregarBloque(TScriptInterface<IBloqueComponente> Bloque);

    virtual void Destruir() override;

private:
    UPROPERTY()
    TArray<TScriptInterface<IBloqueComponente>> Bloques;
};
