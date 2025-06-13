#include "DirectorLaberinto.h"
#include "ILaberintoBuilder.h"
#include "TipoBloque.h"

void ADirectorLaberinto::SetBuilder(ILaberintoBuilder* InBuilder)
{
    Builder = InBuilder;
}

void ADirectorLaberinto::ConstruirMapaEjemplo()
{
    if (!Builder) return;

    Builder->IniciarConstruccion();

    TArray<TArray<ETipoBloque>> Mapa = {
        {ETipoBloque::Cesped, ETipoBloque::Madera, ETipoBloque::Ladrillo, ETipoBloque::Concreto, ETipoBloque::Acero},
        {ETipoBloque::Madera, ETipoBloque::Cesped, ETipoBloque::Concreto, ETipoBloque::Ladrillo, ETipoBloque::Acero},
        {ETipoBloque::Ladrillo, ETipoBloque::Concreto, ETipoBloque::Cesped, ETipoBloque::Madera, ETipoBloque::Acero},
        {ETipoBloque::Acero, ETipoBloque::Ladrillo, ETipoBloque::Madera, ETipoBloque::Cesped, ETipoBloque::Concreto},
        {ETipoBloque::Concreto, ETipoBloque::Acero, ETipoBloque::Ladrillo, ETipoBloque::Madera, ETipoBloque::Cesped}
    };

    for (int32 Y = 0; Y < Mapa.Num(); ++Y)
    {
        for (int32 X = 0; X < Mapa[Y].Num(); ++X)
        {
            Builder->ConstruirBloque(X, Y, Mapa[Y][X]);
        }
    }

    Builder->FinalizarConstruccion();
}
