#include "LaberintoBuilderSimple.h"
#include "BloqueFactorySimple.h"
#include "Bloque.h"

void ULaberintoBuilderSimple::Inicializar(UWorld* InWorld, UBloqueFactorySimple* InFactory)
{
    Mundo = InWorld;
    Factory = InFactory;
}

void ULaberintoBuilderSimple::IniciarConstruccion()
{
    BloquesConstruidos.Empty();
}

void ULaberintoBuilderSimple::ConstruirBloque(int32 X, int32 Y, ETipoBloque Tipo)
{
    if (!Factory || !Mundo) return;

    ABloque* NuevoBloque = Factory->CrearBloque(Mundo, Tipo);
    if (NuevoBloque)
    {
        FVector Posicion(X * 100.0f, Y * 100.0f, 0.0f); // Posición en el mundo
        NuevoBloque->SetActorLocation(Posicion);
        BloquesConstruidos.Add(NuevoBloque);
    }
}

void ULaberintoBuilderSimple::FinalizarConstruccion()
{
    // Nada por ahora
}

const TArray<ABloque*>& ULaberintoBuilderSimple::ObtenerBloquesConstruidos() const
{
    return BloquesConstruidos;
}
