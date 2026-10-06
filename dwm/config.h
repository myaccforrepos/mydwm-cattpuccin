
/* See LICENSE file for copyright and license details. */

/* appearance */
//static const unsigned int borderpx  = 1;
//static const unsigned int snap      = 32;
//static const int showbar            = 1;
//static const int topbar             = 1;
#include <X11/XF86keysym.h>






// USE THE FULL GAPS PATCH





static const char *fonts[]          = { "JetBrains Mono:size=10" };
static const char dmenufont[]       = "JetBrains Mono:size=10";

/* Catppuccin Mocha */
static const char col_base[]        = "#1e1e2e";
static const char col_mantle[]      = "#181825";
static const char col_surface0[]    = "#313244";
static const char col_surface1[]    = "#45475a";
static const char col_text[]        = "#cdd6f4";
static const char col_subtext[]     = "#a6adc8";
static const char col_lavender[]    = "#b4befe";
static const char col_mauve[]       = "#cba6f7";

static const char *colors[][3]      = {
	/*               fg             bg             border */
	[SchemeNorm] = { col_subtext,   col_base,      col_mantle },
	[SchemeSel]  = { col_text,      col_surface0,  col_lavender },
};



static const unsigned int borderpx  = 1;
static const unsigned int snap      = 32;
static const int showbar            = 1;
static const int topbar             = 1;

static const unsigned int gappx     = 10;










/* tagging */
static const char *tags[] = {
	"1", "2", "3", "4", "5", "6", "7", "8", "9"
};

static const Rule rules[] = {
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55;
static const int nmaster     = 1;
static const int resizehints = 1;
static const int lockfullscreen = 1;
static const int refreshrate = 120;

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },
	{ "><>",      NULL },
	{ "[M]",      monocle },
};

/* key definitions */

/* Super / Windows key */
#define MODKEY Mod4Mask

#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0";

static const char *dmenucmd[] = {
	"dmenu_run",
	"-m", dmenumon,
	"-fn", dmenufont,
	"-nb", col_base,
	"-nf", col_text,
	"-sb", col_lavender,
	"-sf", col_base,
	NULL
};

static const char *termcmd[] = { "st", NULL };

static const Key keys[] = {




{ 0, XF86XK_AudioRaiseVolume, spawn, SHCMD("mixer vol=`mixer -os | awk -F= '/^vol.volume=/ {split($2,a,\":\"); v=a[1]+0.05; if(v>1)v=1; printf \"%.2f\",v}'") },
{ 0, XF86XK_AudioLowerVolume, spawn, SHCMD("mixer vol=`mixer -os | awk -F= '/^vol.volume=/ {split($2,a,\":\"); v=a[1]-0.05; if(v<0)v=0; printf \"%.2f\",v}'") },
{ 0, XF86XK_AudioMute,        spawn, SHCMD("mixer vol.mute=toggle") },





	/* modifier                     key          function        argument */

	/* applications */
	{ MODKEY,                       XK_d,        spawn,          {.v = dmenucmd} },
	{ MODKEY,                       XK_Return,   spawn,          {.v = termcmd} },

	/* bar */
	{ MODKEY,                       XK_b,        togglebar,      {0} },

	/* focus */
	{ MODKEY,                       XK_j,        focusstack,     {.i = +1} },
	{ MODKEY,                       XK_k,        focusstack,     {.i = -1} },

	/* master area */
	{ MODKEY,                       XK_i,        incnmaster,     {.i = +1} },
	{ MODKEY,                       XK_p,        incnmaster,     {.i = -1} },

	/* resize master */
	{ MODKEY,                       XK_h,        setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,        setmfact,       {.f = +0.05} },

	/* swap focused window with master */
	{ MODKEY|ShiftMask,                       XK_Return,   zoom,           {0} },

	/* previous view */
	{ MODKEY,                       XK_Tab,      view,           {0} },

	/* kill focused window */
	{ MODKEY,                       XK_q,        killclient,     {0} },

	/* layouts */
	{ MODKEY,                       XK_t,        setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,        setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,        setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,    setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,    togglefloating, {0} },

	/* view all tags */
	{ MODKEY,                       XK_0,        view,           {.ui = ~0} },
	{ MODKEY|ShiftMask,             XK_0,        tag,            {.ui = ~0} },

	/* monitor focus */
	{ MODKEY,                       XK_comma,     focusmon,       {.i = -1} },
	{ MODKEY,                       XK_period,    focusmon,       {.i = +1} },
	{ MODKEY|ShiftMask,             XK_comma,     tagmon,         {.i = -1} },
	{ MODKEY|ShiftMask,             XK_period,    tagmon,         {.i = +1} },

	/* AZERTY tags: Super + A/Z/E/R/T/Y */
	TAGKEYS(                        XK_a,                      0)
	TAGKEYS(                        XK_z,                      1)
	TAGKEYS(                        XK_e,                      2)
	TAGKEYS(                        XK_r,                      3)
	TAGKEYS(                        XK_t,                      4)
	TAGKEYS(                        XK_y,                      5)

	/* remaining tags */
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)

	/* quit dwm */
	{ MODKEY|ShiftMask,             XK_q,        quit,           {0} },
};

/* button definitions */
static const Button buttons[] = {
	{ ClkLtSymbol,   0,              Button1, setlayout,      {0} },
	{ ClkLtSymbol,   0,              Button3, setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,   0,              Button2, zoom,           {0} },
	{ ClkStatusText, 0,              Button2, spawn,           {.v = termcmd} },

	{ ClkClientWin,  MODKEY,         Button1, movemouse,      {0} },
	{ ClkClientWin,  MODKEY,         Button2, togglefloating, {0} },
	{ ClkClientWin,  MODKEY,         Button3, resizemouse,    {0} },

	{ ClkTagBar,     0,              Button1, view,           {0} },
	{ ClkTagBar,     0,              Button3, toggleview,     {0} },
	{ ClkTagBar,     MODKEY,         Button1, tag,             {0} },
	{ ClkTagBar,     MODKEY,         Button3, toggletag,       {0} },
};
