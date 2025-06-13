#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TipoBloque.h"
#include "BloqueFactorySimple.h"
#include "ILaberintoBuilder.h"
#include "BomberMan_012025GameMode.generated.h"
#include "LaberintoFacade.h"
class ABloque; class ABloqueAcero; class ABloqueCesped; class ABloqueConcreto; class ABloqueLadrillo; class ABloqueMadera;
UCLASS(minimalapi)
class ABomberMan_012025GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
    ABomberMan_012025GameMode();

protected:
    virtual void BeginPlay() override;

private:
    // Fábrica para crear bloques clonando prototipos
    UPROPERTY()
    UBloqueFactorySimple* BloqueFactory;

    // Builder que construye el laberinto
    TUniquePtr<ULaberintoBuilderSimple> LaberintoBuilder;
};



