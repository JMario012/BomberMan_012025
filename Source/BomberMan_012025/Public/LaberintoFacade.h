#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LaberintoFacade.generated.h"

class UBloqueFactorySimple;
class ULaberintoBuilderSimple;
class ADirectorLaberinto;

/**
 * Fachada que simplifica la creación de laberintos.
 */
UCLASS()
class BOMBERMAN_012025_API ULaberintoFacade : public UObject
{
    GENERATED_BODY()

public:
    UFUNCTION()
    void GenerarLaberintoEjemplo(UWorld* Mundo);

private:
    UBloqueFactorySimple* Factory;
    ULaberintoBuilderSimple* Builder;
    ADirectorLaberinto* Director;
};
