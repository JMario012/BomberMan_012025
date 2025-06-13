#pragma once

#include "CoreMinimal.h"
#include "PlanoLaberinto.generated.h"

UCLASS()
class BOMBERMAN_012025_API UPlanoLaberinto : public UObject
{
    GENERATED_BODY()

public:
    void AgregarBloque(class ABloque* Bloque);

    const TArray<ABloque*>& ObtenerBloques() const;

private:
    TArray<ABloque*> Bloques;
};
