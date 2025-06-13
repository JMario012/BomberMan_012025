#include "PlanoLaberinto.h"
#include "Bloque.h"

void UPlanoLaberinto::AgregarBloque(ABloque* Bloque)
{
    Bloques.Add(Bloque);
}

const TArray<ABloque*>& UPlanoLaberinto::ObtenerBloques() const
{
    return Bloques;
}
