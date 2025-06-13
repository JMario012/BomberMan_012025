#include "BloqueConcretoClonable.h"
#include "Engine/World.h"

ABloque* ABloqueConcretoClonable::Clonar(UWorld* World, const FVector& Posicion)
{
    return World->SpawnActor<ABloqueConcretoClonable>(GetClass(), Posicion, FRotator::ZeroRotator);
}