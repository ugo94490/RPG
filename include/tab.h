/*
** EPITECH PROJECT, 2019
** tab.h
** File description:
** tab.h
*/

#ifndef TAB_H
#define TAB_H

static char *player[4] =
{
    "assets/back_train2.png",
    "assets/back_train2.png",
    "assets/back_train.png",
    "assets/back_train.png"
};

static atk_t atks[4] =
{
    {0, 20},
    {1, 100},
    {2, 50},
    {3, 70}
};

static char *name[21] =
{
    "Ouisticram",
    "Tiplouf",
    "Tortipouss",
    "Chimpenfeu",
    "Prinplouf",
    "Boskerra",
    "Simiabraz",
    "Pingoleon",
    "Torterra",
    "Etourmi",
    "Etouraptor",
    "Keunotor",
    "Castorno",
    "Lixy",
    "Luxray",
    "Charkos",
    "Bastiodon",
    "Dialga",
    "Palkia",
    "Arceus",
    NULL
};

static char *atk[3] =
{
    "Hydrocanon",
    "Ultralaser",
    NULL
};

static char *asset_atk[2] =
{
    "assets/hydrocanon.png",
    "assets/ultralaser.png"
};

static char *front_pkm[20] =
{
    "assets/front/ouisticram.png",
    "assets/front/tiplouf.png",
    "assets/front/tortipouss.png",
    "assets/front/chimpenfeu.png",
    "assets/front/prinplouf.png",
    "assets/front/boskerra.png",
    "assets/front/simiabraz.png",
    "assets/front/pingoleon.png",
    "assets/front/torterra.png",
    "assets/front/etourmi.png",
    "assets/front/etouraptor.png",
    "assets/front/keunotor.png",
    "assets/front/castorno.png",
    "assets/front/lixy.png",
    "assets/front/luxray.png",
    "assets/front/charkos.png",
    "assets/front/bastiodon.png",
    "assets/front/dialga.png",
    "assets/front/palkia.png",
    "assets/front/arceus.png"
};

static char *back_pkm[20] =
{
    "assets/back/ouisticram.png",
    "assets/back/tiplouf.png",
    "assets/back/tortipouss.png",
    "assets/back/chimpenfeu.png",
    "assets/back/prinplouf.png",
    "assets/back/boskerra.png",
    "assets/back/simiabraz.png",
    "assets/back/pingoleon.png",
    "assets/back/torterra.png",
    "assets/back/etourmi.png",
    "assets/back/etouraptor.png",
    "assets/back/keunotor.png",
    "assets/back/castorno.png",
    "assets/back/lixy.png",
    "assets/back/luxray.png",
    "assets/back/charkos.png",
    "assets/back/bastiodon.png",
    "assets/back/dialga.png",
    "assets/back/palkia.png",
    "assets/back/arceus.png"
};

static char *atk_name[4] =
{
    "Charge",
    "Hydrocanon",
    "Ultralaser",
    "OmegaLOL"
};

static char *phr[3] =
{
    " attaque ",
    " !",
    " est K.O !"
};

static sfVector2f atk_pos[4] =
{
    {342, 536},
    {342, 683},
    {645, 536},
    {645, 683}
};

static sfVector2f pos_txt[8] =
{
    {880, 328},
    {815, 328},
    {885, 280},
    {535, 141},
    {340, 135},
    {700, 275},
    {355, 165},
    {415, 165}
};

static sfVector2f atk_txt[8] =
{
    {372, 566},
    {372, 713},
    {675, 566},
    {675, 713},
    {524, 622},
    {524, 769},
    {827, 622},
    {827, 769}
};

#endif
