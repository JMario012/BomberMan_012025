#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DirectorLaberinto.generated.h"

class ILaberintoBuilder;

UCLASS()
class BOMBERMAN_012025_API ADirectorLaberinto : public AActor
{
    GENERATED_BODY()

public:
    void SetBuilder(ILaberintoBuilder* InBuilder);
    void ConstruirMapaEjemplo();

private:
    ILaberintoBuilder* Builder;
};
