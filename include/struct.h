/*
** EPITECH PROJECT, 2023
** my_rpg
** File description:
** struct
*/

#pragma once
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Audio.h>

#define CO (pk->sc->event.type == sfEvtMouseButtonReleased)
#define ND (pk->sc->event.mouseButton.button == sfMouseLeft)

typedef struct screen_s {
    sfRenderWindow *window;
    sfEvent event;
} screen_t;

typedef struct menu_s {
    sfTexture *tbm;
    sfSprite *sbm;
    sfVector2f pbm;

    sfTexture *tlm;
    sfSprite *slm;
    sfVector2f plm;
    sfIntRect blm;

    sfTexture *tqm;
    sfSprite *sqm;
    sfVector2f pqm;
    sfIntRect bqm;

    sfTexture *tcm;
    sfSprite *scm;
    sfVector2f pcm;
    sfIntRect bcm;

    sfTexture *tnm;
    sfSprite *snm;
    sfVector2f pnm;
    sfIntRect bnm;

    sfTexture *tom;
    sfSprite *som;
    sfVector2f pom;
    sfIntRect bom;

    sfTexture *tod;
    sfSprite *sod;
    sfVector2f pod;

    sfTexture *tcd;
    sfSprite *scd;
    sfVector2f pcd;

    sfTexture *ttest;
    sfSprite *stest;
    sfVector2f ptest;

    sfFont *fe;
    sfText *te;
    int s;
} menu_t;

typedef struct charact_s {
    sfTexture *tpl;
    sfSprite *spl;
    sfVector2f ppl;
    sfIntRect bpl;

    sfTexture *tpv;
    sfSprite *spv;
    sfVector2f ppv;
    sfIntRect bpv;

    sfTexture *tst;
    sfSprite *sst;
    sfVector2f pst;
    sfIntRect bst;

    sfTexture *tca;
    sfSprite *sca;
    sfVector2f pca;
    sfIntRect bca;

    sfTexture *tfo;
    sfSprite *sfo;
    sfVector2f pfo;
    sfIntRect bfo;

    int hp;
    int deg;
    int st;
    int fa;
    int mvt;
    int mvl;
    int mvr;
    int mvd;
    sfClock *frame;
    sfClock *cdmv;
    sfView *view;

    int kick;
    int kcd;
    int combo;
    int combocd;
    sfClock *ckick;
    sfClock *ccombo;
    sfRectangleShape *hitbox;
    sfRectangleShape *kickbox;
    sfVector2f lc;
    sfVector2f rc;
    sfVector2f tc;
    sfVector2f dc;
} charact_t;

typedef struct rat_s {
    sfSprite *srat;
    sfTexture *trat;
    sfVector2f ratpos;
    sfIntRect ssrat;
    sfRectangleShape *hitbox;
    sfRectangleShape *slambox;
    sfSoundBuffer *laugh;
    sfSoundBuffer *slam1;
    sfSound *ratsound;
    int sit;
    int pv;
    int alive;
    int cd;
    sfClock *crat;
    struct rat_s *next;
    struct rat_s *prev;
} rat_t;

typedef struct knight_s {
    sfSprite *skni;
    sfTexture *tkni;
    sfVector2f knipos;
    sfIntRect sskni;
    sfRectangleShape *hitbox;
    sfRectangleShape *slambox;
    sfSoundBuffer *walk1;
    sfSoundBuffer *walk2;
    sfSoundBuffer *slam1;
    sfSoundBuffer *slam2;
    sfSoundBuffer *slam3;
    sfSound *ksound;
    int sit;
    int pv;
    int alive;
    int cd;
    sfClock *ckni;
    struct knight_s *next;
    struct knight_s *prev;
} knight_t;

typedef struct paragon_s {
    sfSprite *spar;
    sfTexture *tpar;
    sfVector2f parpos;
    sfIntRect sspar;
    sfRectangleShape *hitbox;
    sfRectangleShape *slambox;
    sfSoundBuffer *taunt;
    sfSoundBuffer *slam1;
    sfSound *parsound;
    int sit;
    int pv;
    int alive;
    int cd;
    sfClock *cpar;
    struct paragon_s *next;
    struct paragon_s *prev;
} paragon_t;

typedef struct beholder_s {
    sfSprite *sbeh;
    sfTexture *tbeh;
    sfVector2f epos;
    struct beholder_s *next;
    struct beholder_s *prev;
} beholder_t;

typedef struct reaper_s {
    sfSprite *srea;
    sfTexture *trea;
    sfRectangleShape *hitbox;
    sfRectangleShape *slambox;
    sfVector2f epos;
    sfIntRect ssrea;
    sfClock *crea;
    sfSoundBuffer *walk1;
    sfSoundBuffer *walk2;
    sfSoundBuffer *walk3;
    sfSoundBuffer *walk4;
    sfSoundBuffer *slam;
    sfSoundBuffer *slamv;
    sfSound *reasound;
    sfSound *reasound2;
    int sit;
    int alive;
    int pv;
} reaper_t;

typedef struct enemy_s {
    rat_t *rats;
    knight_t *knights;
    paragon_t *paragons;
    beholder_t *beholders;
    reaper_t *reaper;
    int c;
    int x;
    int y;
} enemy_t;

typedef struct DLighthitbox_s {
    sfRectangleShape *hitbox;
    int x;
    int y;
    int sx;
    int sy;
    struct DLighthitbox_s *next;
    struct DLighthitbox_s *prev;
} dlighthitbox_t;

typedef struct Dlight_s {
    sfVertexArray *LVA;
    sfVertexArray *SLVA;
    sfRectangleShape *rectest;
    dlighthitbox_t *hb;
    sfClock *lighcd;
    int sloaded;
    int wsload;
    int x;
    int y;
    int sx;
    int sy;
    int c;
    int *ashadbox;
} Dlight_t;

typedef struct intersect_s {
    int x0;
    int y0;
    int x1;
    int y1;
    int dx;
    int dy;
    int sx;
    int sy;
    int err;
}intersect_t;

typedef struct inventory_s {
    sfTexture *tfi;
    sfSprite *sfi;
    sfVector2f pfi;

    int ivo;
    int ire;
    sfTexture *tca;
    sfSprite *sca;

    int icc;
    int cas;
    int condition;
    sfTexture *tcb;
    sfSprite *scb;
    sfVector2f mp;

    int ca;
    int cb;
    int cc;
    int cd;
    int ce;
    int cf;
    int cg;
    int ch;
    int ci;
    int cj;
    int ck;
    int cl;
    int cm;
    int cn;
    int co;
    int cp;
    int cq;
    int cr;
    int cs;
    int ct;
    int cu;
    int cv;
    int cw;
    int cx;
} inventory_t;

typedef struct items_s {
    sfTexture *ti1;
    sfSprite *si1;

    sfTexture *ti2;
    sfSprite *si2;
    sfTexture *ti3;
    sfSprite *si3;
    sfTexture *ti4;
    sfSprite *si4;

    sfTexture *ti10;
    sfSprite *si10;

    sfTexture *ti20;
    sfSprite *si20;

    sfTexture *ti30;
    sfSprite *si30;

    sfTexture *ti40;
    sfSprite *si40;

    sfTexture *ti50;
    sfSprite *si50;
    sfTexture *ti51;
    sfSprite *si51;
    sfTexture *ti52;
    sfSprite *si52;
    sfTexture *ti53;
    sfSprite *si53;
} items_t;

typedef struct game_s {
    sfTexture *tbg;
    sfSprite *sbg;
    sfVector2f pbg;
    sfTexture *tbghb;
    sfSprite *sbghb;
    sfImage *ibghb;
    sfSprite *sportal1;
    sfTexture *tportal1;
    sfSprite *sportal2;
    sfTexture *tportal2;
    sfView *mainmenu;
    sfView *gui;
    sfView *inv;
    sfRectangleShape *sto;
    sfText *talk;
    sfFont *font;
    sfView *ta;
    sfMusic *mainmusic;
    sfMusic *gardenmusic;
    sfMusic *manormusic;
    sfMusic *bossmusic;
    int cportal;
    int pmusic;
    int cmusic;
    int dialog;
    int dcd;
    int end;
    char **dialoglist;
    sfText *tcinema;
    sfFont *fcinema;
    sfClock *ccinema;
    sfClock *sldportal;
    sfRectangleShape *bbg;
    sfRectangleShape *rend;
    sfSprite *spnj;
    sfTexture *tpnj;
    sfRectangleShape *tpretss;
    sfRectangleShape *tprettop1;
    sfRectangleShape *tprettop2;
    int save;
    int tmpsave;
    int xpsave;
    int ypsave;
    int alivesave;
    char *alivesave2;
    sfSprite *ssave;
    sfTexture *tsave;
    sfRectangleShape *savebox;
} game_t;

typedef struct option_s {
    sfTexture *tres;
    sfSprite *sres;
    sfVector2f pres;

    sfTexture *tgs;
    sfSprite *sgs;
    sfVector2f pgs;
    sfIntRect bgs;

    sfTexture *tls;
    sfSprite *sls;
    sfVector2f pls;
    sfIntRect bls;

    sfTexture *tqh;
    sfSprite *sqh;
    sfVector2f pqh;
    sfIntRect bqh;

    sfTexture *tqm;
    sfSprite *sqm;
    sfVector2f pqm;
    sfIntRect bqm;

    sfTexture *tql;
    sfSprite *sql;
    sfVector2f pql;
    sfIntRect bql;

    sfTexture *toff;
    sfSprite *soff;
    sfVector2f poff;
    sfIntRect boff;

    sfTexture *tctr;
    sfSprite *sctr;
    sfVector2f pctr;

    sfTexture *tdyn;
    sfSprite *sdyn;
    sfVector2f pdyn;

    sfTexture *tcon;
    sfSprite *scon;
    sfVector2f pcon;

    int light;
    int lightof;
    int res;
} option_t;


typedef struct pause_s {
    int i;
    int j;
    int k;
    sfView *pa;
    sfTexture *tres;
    sfSprite *sres;
    sfVector2f pres;
    sfIntRect bres;
} pause_t;

typedef struct package_s {
    screen_t *sc;
    menu_t *mn;
    game_t *ga;
    pause_t *pa;
    int scene;
    charact_t *ct;
    sfVector2i ps;
    sfVector2f cos;
    inventory_t *iv;
    items_t *it;
    Dlight_t *DL;
    enemy_t *en;
    option_t *opt;
} package_t;
