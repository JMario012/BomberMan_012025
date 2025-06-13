#include "BomberMan_012025GameMode.h"
#include "Bloque.h"
#include "BloqueCesped.h"
#include "BloqueMadera.h"
#include "BloqueLadrillo.h"
#include "BloqueConcreto.h"
#include "BloqueAcero.h"
#include "Engine/World.h"

ABomberMan_012025GameMode::ABomberMan_012025GameMode()
{
    // Constructor base, no necesitas lógica aquí aún
}

void ABomberMan_012025GameMode::BeginPlay()
{
    Super::BeginPlay();

    UWorld* World = GetWorld();
    if (!World) return;

    // Crear e inicializar la fábrica
    BloqueFactory = NewObject<UBloqueFactorySimple>();

    // Registrar prototipos por tipo (solo una vez)
    BloqueFactory->RegistrarPrototipo(ETipoBloque::Cesped, World->SpawnActor<ABloqueCesped>());
    BloqueFactory->RegistrarPrototipo(ETipoBloque::Madera, World->SpawnActor<ABloqueMadera>());
    BloqueFactory->RegistrarPrototipo(ETipoBloque::Ladrillo, World->SpawnActor<ABloqueLadrillo>());
    BloqueFactory->RegistrarPrototipo(ETipoBloque::Concreto, World->SpawnActor<ABloqueConcreto>());
    BloqueFactory->RegistrarPrototipo(ETipoBloque::Acero, World->SpawnActor<ABloqueAcero>());

    // Crear e inicializar el builder
    LaberintoBuilder = MakeUnique<ULaberintoBuilderSimple>();
    LaberintoBuilder->Inicializar(World, BloqueFactory);

    // Crear y usar el director del laberinto
    ADirectorLaberinto* Director = World->SpawnActor<ADirectorLaberinto>();
    if (Director)
    {
        Director->SetBuilder(LaberintoBuilder.Get());
        Director->ConstruirMapaEjemplo(); // Aquí defines cómo es el laberinto
    }
    Super::BeginPlay();

    ULaberintoFacade* Facade = NewObject<ULaberintoFacade>();
    Facade->GenerarLaberintoEjemplo(GetWorld());
}
