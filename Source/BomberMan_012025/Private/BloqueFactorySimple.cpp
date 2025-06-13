#include "BloqueFactorySimple.h"
#include "Bloque.h"
#include "Engine/World.h"

ABloque* UBloqueFactorySimple::CrearBloque(UWorld* World, ETipoBloque Tipo)
{
    if (!World) return nullptr;

    if (Prototipos.Contains(Tipo))
    {
        ABloque* Clon = Prototipos[Tipo]->Clonar(World);

        if (Clon)
        {
            CodigosDeBloques.Add(static_cast<int32>(Tipo));
            // Comportamiento grupal: destruirse
            // Clon->DestruirBloque(); // solo si lo quieres inmediato
        }

        return Clon;
    }

    // Si no existe prototipo registrado
    UE_LOG(LogTemp, Warning, TEXT("No hay prototipo registrado para el tipo de bloque."));
    return nullptr;
}

void UBloqueFactorySimple::RegistrarPrototipo(ETipoBloque Tipo, ABloque* Prototipo)
{
    if (Prototipo && !Prototipos.Contains(Tipo))
    {
        Prototipos.Add(Tipo, Prototipo);
        CodigosDeBloques.Add(static_cast<int32>(Tipo));
    }
}
