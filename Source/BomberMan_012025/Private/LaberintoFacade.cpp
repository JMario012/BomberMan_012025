#include "LaberintoFacade.h"
#include "Bloques/BloqueFactorySimple.h"
#include "Builder/LaberintoBuilderSimple.h"
#include "Builder/DirectorLaberinto.h"
#include "Bloques/BloqueCesped.h"
#include "Bloques/BloqueMadera.h"
#include "Bloques/BloqueLadrillo.h"
#include "Bloques/BloqueConcreto.h"
#include "Bloques/BloqueAcero.h"

void ULaberintoFacade::GenerarLaberintoEjemplo(UWorld* Mundo)
{
    if (!Mundo) return;

    // Crear fábrica y registrar prototipos
    Factory = NewObject<UBloqueFactorySimple>();
    Factory->RegistrarPrototipo(0, NewObject<ABloqueCesped>(Mundo));
    Factory->RegistrarPrototipo(1, NewObject<ABloqueMadera>(Mundo));
    Factory->RegistrarPrototipo(2, NewObject<ABloqueLadrillo>(Mundo));
    Factory->RegistrarPrototipo(3, NewObject<ABloqueConcreto>(Mundo));
    Factory->RegistrarPrototipo(4, NewObject<ABloqueAcero>(Mundo));

    // Crear Builder y asignarle la fábrica
    Builder = NewObject<ULaberintoBuilderSimple>();
    Builder->EstablecerFactory(Factory);

    // Crear director y asignarle el builder
    Director = Mundo->SpawnActor<ADirectorLaberinto>();
    Director->EstablecerBuilder(Builder);

    // Construir laberinto
    Director->ConstruirMapaEjemplo();
}
