/* See LICENSE file for copyright and license details. */
#include <X11/XF86keysym.h>

/* appearance */
/* border pixel of windows */
static const unsigned int borderpx = 0;

/* to switch back to default border after
 * dynamic border resizing via keybinds */
static const unsigned int default_border = 0;

/* snap pixel */
static const unsigned int snap = 32;

/* horiz inner gap between windows */
static const unsigned int gappih = 10;

/* vert inner gap between windows */
static const unsigned int gappiv = 10;

/* horiz outer gap between windows and screen edge */
static const unsigned int gappoh = 10;

/* vert outer gap between windows and screen edge */
static const unsigned int gappov = 10;

/* 1 means no outer gap when there is only one window */
static const int smartgaps = 0;

/* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systraypinning = 0;

/* systray spacing */
static const unsigned int systrayspacing = 2;

/* 1: if pinning fails,display systray on the 1st monitor,False: display systray
 * on last monitor */
static const int systraypinningfailfirst = 1;

/* 0 means no systray */
static const int showsystray = 1;

/* 0 means no bar */
static const int showbar = 1;

static const int showtab = showtab_auto;

/* 0 means bottom tab */
static const int toptab = 1;

/* 1 means the bar will float(don't have padding),
 * 0 means the bar have padding */
static const int floatbar = 1;

/* 0 means bottom bar */
static const int topbar = 1;

static const int horizpadbar = 5;
static const int vertpadbar = 11;
static const int vertpadtab = 35;
static const int horizpadtabi = 15;
static const int horizpadtabo = 15;
static const int scalepreview = 4;

/* 1 means enable, 0 is off */
static const int tag_preview = 1;

/* 0 means use SchemeSel for selected non vacant tag */
static const int colorfultag = 1;

/* 1 means the new window will attach on the end; 0 means the new window will
 * attach on the front,default is front */
static const int new_window_attach_on_end = 0;

/* icon size */
#define ICONSIZE 19

/* space between icon and title */
#define ICONSPACING 8

static const char *fonts[] = {
    "CaskaydiaMono:style:medium:size=12",
    "CaskaydiaMono Nerd Font Mono:style:medium:size=19"};
static const char dmenufont[] = "CaskaydiaMono Nerd Font Mono:pixelsize=15";

// theme
#include "themes/catppuccin.h"

/* volume controls */
static const char *upvol[] = {"amixer", "-q", "sset", "Master", "5%+", NULL};
static const char *downvol[] = {"amixer", "-q", "sset", "Master", "5%-", NULL};
static const char *mutevol[] = {"amixer", "-q",     "sset",
                                "Master", "toggle", NULL};
static const char *light_up[] = {"brightnessctl", "s", "5+", NULL};
static const char *light_down[] = {"brightnessctl", "s", "5-", NULL};

static const char *colors[][3] = {
    /* fg, bg, border */
    [SchemeNorm] = {gray3, black, gray2},
    [SchemeSel] = {gray4, blue, blue},
    [SchemeTitle] = {white, black, black}, // active window title
    [TabSel] = {blue, gray2, black},
    [TabNorm] = {gray3, black, black},
    [SchemeTag] = {gray3, black, black},
    [SchemeTag1] = {blue, black, black},
    [SchemeTag2] = {red, black, black},
    [SchemeTag3] = {orange, black, black},
    [SchemeTag4] = {green, black, black},
    [SchemeTag5] = {pink, black, black},
    [SchemeLayout] = {green, black, black},
    [SchemeBtnPrev] = {green, black, black},
    [SchemeBtnNext] = {yellow, black, black},
    [SchemeBtnClose] = {red, black, black},
};

/* tagging */
static char *tags[] = {"一", "二", "三", "四", "五"};

static const char *eww[] = {"eww", "open", "eww", NULL};

static const Launcher launchers[] = {
    /* command     name to display */
    {eww, ""},
};

static const int tagschemes[] = {SchemeTag1, SchemeTag2, SchemeTag3, SchemeTag4,
                                 SchemeTag5};

/* horizontal padding between the underline and tag */
static const unsigned int ulinepad = 5;

/* thickness / height of the underline */
static const unsigned int ulinestroke = 2;

/* how far above the bottom of the bar the line should appear */
static const unsigned int ulinevoffset = 0;

/* 1 to show underline on all tags, 0 for just the active ones */
static const int ulineall = 0;

static const Rule rules[] = {
    /* xprop(1):
     *	WM_CLASS(STRING) = instance, class
     *	WM_NAME(STRING) = title
     */
    /* class      instance    title       tags mask     iscentered   isfloating
       monitor */
    {"eww", NULL, NULL, 0, 0, 1, -1},
};

/* layout(s) */
static const float mfact = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster = 1;    /* number of clients in master area */
static const int resizehints =
    0; /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen =
    1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT                                                           \
  1 /* nrowgrid layout: force two clients to always split vertically */
#include "functions.h"

static const Layout layouts[] = {
    /* symbol     arrange function */
    {"[]=", tile}, /* first entry is default */
    {"[M]", monocle},
    {"[@]", spiral},
    {"[\\]", dwindle},
    {"H[]", deck},
    {"TTT", bstack},
    {"===", bstackhoriz},
    {"HHH", grid},
    {"###", nrowgrid},
    {"---", horizgrid},
    {":::", gaplessgrid},
    {"|M|", centeredmaster},
    {">M>", centeredfloatingmaster},
    {"><>", NULL}, /* no layout function means floating behavior */
    {NULL, NULL},
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY, TAG)                                                      \
  {MODKEY, KEY, view, {.ui = 1 << TAG}},                                       \
      {MODKEY | ControlMask, KEY, toggleview, {.ui = 1 << TAG}},               \
      {MODKEY | ShiftMask, KEY, tag, {.ui = 1 << TAG}},                        \
      {MODKEY | ControlMask | ShiftMask, KEY, toggletag, {.ui = 1 << TAG}},

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd)                                                             \
  {                                                                            \
    .v = (const char *[]) { "/bin/zsh", "-c", cmd, NULL }                      \
  }

/* commands */
static char dmenumon[2] = "0";
static const char *dmenucmd[] = {"dmenu_run", "-i", "-m",  dmenumon,
                                 "-fn",       dmenufont, NULL};
static const char *browsercmd[] = {"librewolf", NULL};

static const Key keys[] = {
    /* modifier                         key         function        argument */

    // brightness and audio
    {MODKEY | ShiftMask, XK_equal, spawn, {.v = upvol}},
    {MODKEY | ShiftMask, XK_minus, spawn, {.v = downvol}},
    {MODKEY | ShiftMask, XK_m, spawn, {.v = mutevol}},
    {0, XF86XK_MonBrightnessUp, spawn, {.v = light_up}},
    {0, XF86XK_MonBrightnessDown, spawn, {.v = light_down}},

    // screenshot fullscreen and cropped
    {MODKEY | ControlMask, XK_u, spawn,
     SHCMD("maim | xclip -selection clipboard -t image/png")},
    {MODKEY, XK_u, spawn,
     SHCMD("maim --select | xclip -selection clipboard -t image/png")},

    {MODKEY, XK_p, spawn, {.v = dmenucmd}},
    {MODKEY | ShiftMask, XK_Return, spawn, SHCMD("st")},

    /* Common software */
    {MODKEY, XK_w, spawn, {.v = browsercmd}},
    {MODKEY | ShiftMask, XK_y, spawn, SHCMD("freetube")},
    {MODKEY, XK_e, spawn, SHCMD("st -e yazi")},
    {MODKEY | ShiftMask, XK_s, spawn, SHCMD("flameshot gui")},
    {MODKEY | ShiftMask, XK_k, spawn, SHCMD("bitwarden-desktop")},
    {MODKEY | ShiftMask, XK_g, spawn, SHCMD("steam")},

    /* Quit, reboot, shutdown */
    {MODKEY | ShiftMask, XK_e, spawn,
     SHCMD("~/.local/bin/prompt 'Do you really want to quit?' 'killall bar.sh "
           "chadwm'")},
    {MODKEY | ShiftMask, XK_x, spawn,
     SHCMD("~/.local/bin/prompt 'Do you really want to shutdown the system?' "
           "'loginctl poweroff'")},
    {MODKEY | ShiftMask, XK_r, spawn,
     SHCMD("~/.local/bin/prompt 'Do you really want to reboot the system?' "
           "'loginctl reboot'")},

    /* Emoji dmenu script */
    {MODKEY, XK_ccedilla, spawn, SHCMD("~/.scripts/dmenuunicode")},
    // toggle stuff
    {MODKEY, XK_b, togglebar, {0}},
    {MODKEY | ControlMask, XK_t, togglegaps, {0}},
    {MODKEY | ShiftMask, XK_space, togglefloating, {0}},
    {MODKEY, XK_f, togglefullscr, {0}},

    {MODKEY | ControlMask, XK_w, tabmode, {-1}},
    {MODKEY, XK_j, focusstack, {.i = +1}},
    {MODKEY, XK_k, focusstack, {.i = -1}},
    {MODKEY, XK_i, incnmaster, {.i = +1}},
    {MODKEY, XK_d, incnmaster, {.i = -1}},

    // shift view
    {MODKEY, XK_Left, shiftview, {.i = -1}},
    {MODKEY, XK_Right, shiftview, {.i = +1}},

    // change m,cfact sizes
    {MODKEY, XK_h, setmfact, {.f = -0.05}},
    {MODKEY, XK_l, setmfact, {.f = +0.05}},
    {MODKEY | ShiftMask, XK_h, setcfact, {.f = +0.25}},
    {MODKEY | ShiftMask, XK_l, setcfact, {.f = -0.25}},
    {MODKEY | ShiftMask, XK_o, setcfact, {.f = 0.00}},

    /*{ MODKEY|ShiftMask,                 XK_j,       movestack,      {.i = +1 }
       },*/
    /*{ MODKEY|ShiftMask,                 XK_k,       movestack,      {.i = -1 }
       },*/
    {MODKEY, XK_Return, zoom, {0}},
    {MODKEY, XK_Tab, view, {0}},

    // overall gaps
    /*{ MODKEY|ControlMask,               XK_i,       incrgaps,       {.i = +1 }
       },*/
    /*{ MODKEY|ControlMask,               XK_d,       incrgaps,       {.i = -1 }
       },*/

    // inner gaps
    {MODKEY | ShiftMask, XK_i, incrigaps, {.i = +1}},
    {MODKEY | ControlMask | ShiftMask, XK_i, incrigaps, {.i = -1}},

    // outer gaps
    {MODKEY | ControlMask, XK_o, incrogaps, {.i = +1}},
    {MODKEY | ControlMask | ShiftMask, XK_o, incrogaps, {.i = -1}},

    // inner+outer hori, vert gaps
    {MODKEY | ControlMask, XK_6, incrihgaps, {.i = +1}},
    {MODKEY | ControlMask | ShiftMask, XK_6, incrihgaps, {.i = -1}},
    {MODKEY | ControlMask, XK_7, incrivgaps, {.i = +1}},
    {MODKEY | ControlMask | ShiftMask, XK_7, incrivgaps, {.i = -1}},
    {MODKEY | ControlMask, XK_8, incrohgaps, {.i = +1}},
    {MODKEY | ControlMask | ShiftMask, XK_8, incrohgaps, {.i = -1}},
    {MODKEY | ControlMask, XK_9, incrovgaps, {.i = +1}},
    {MODKEY | ControlMask | ShiftMask, XK_9, incrovgaps, {.i = -1}},

    {MODKEY | ControlMask | ShiftMask, XK_d, defaultgaps, {0}},

    // layout
    {MODKEY, XK_t, setlayout, {.v = &layouts[0]}},
    {MODKEY, XK_y, setlayout, {.v = &layouts[1]}},
    {MODKEY, XK_m, setlayout, {.v = &layouts[2]}},
    {MODKEY, XK_g, setlayout, {.v = &layouts[11]}},
    {MODKEY | ControlMask, XK_g, setlayout, {.v = &layouts[10]}},
    {MODKEY | ControlMask | ShiftMask, XK_t, setlayout, {.v = &layouts[13]}},
    {MODKEY, XK_space, setlayout, {0}},
    {MODKEY | ControlMask, XK_comma, cyclelayout, {.i = -1}},
    {MODKEY | ControlMask, XK_period, cyclelayout, {.i = +1}},
    {MODKEY, XK_0, view, {.ui = ~0}},
    {MODKEY | ShiftMask, XK_0, tag, {.ui = ~0}},

    /* NAVIGATION BETWEEN MULTI MONITOR SETUP */
    {MODKEY, XK_comma, focusmon, {.i = -1}},
    {MODKEY, XK_period, focusmon, {.i = +1}},
    {MODKEY | ShiftMask, XK_comma, tagmon, {.i = -1}},
    {MODKEY | ShiftMask, XK_period, tagmon, {.i = +1}},

    // change border size
    /*{ MODKEY|ShiftMask,                 XK_minus,   setborderpx,    {.i = -1 }
       },*/
    /*{ MODKEY|ShiftMask,                 XK_p,       setborderpx,    {.i = +1 }
       },*/
    /*{ MODKEY|ShiftMask,                 XK_w,       setborderpx,    {.i =
       default_border } },*/

    // kill window
    {MODKEY | ShiftMask, XK_q, killclient, {0}},

    // restart
    {MODKEY | ControlMask, XK_r, restart, {0}},

    // hide & restore windows
    {MODKEY | ControlMask, XK_d, hidewin, {0}},
    {MODKEY | ShiftMask, XK_d, restorewin, {0}},

    TAGKEYS(XK_1, 0) TAGKEYS(XK_2, 1) TAGKEYS(XK_3, 2) TAGKEYS(XK_4, 3)
        TAGKEYS(XK_5, 4) TAGKEYS(XK_6, 5) TAGKEYS(XK_7, 6) TAGKEYS(XK_8, 7)
            TAGKEYS(XK_9, 8)};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
 * ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask      button          function argument */
    {ClkLtSymbol, 0, Button1, setlayout, {0}},
    {ClkLtSymbol, 0, Button3, setlayout, {.v = &layouts[2]}},
    {ClkWinTitle, 0, Button2, zoom, {0}},
    {ClkStatusText, 0, Button2, spawn, SHCMD("st")},

    /* Keep movemouse? */
    /* { ClkClientWin,         MODKEY,         Button1,        movemouse, {0} },
     */

    /* placemouse options, choose which feels more natural:
     *    0 - tiled position is relative to mouse cursor
     *    1 - tiled position is relative to window center
     *    2 - mouse pointer warps to window center
     *
     * The moveorplace uses movemouse or placemouse depending on the floating
     * state of the selected client. Set up individual keybindings for the two
     * if you want to control these separately (i.e. to retain the feature to
     * move a tiled window into a floating position).
     */
    {ClkClientWin, MODKEY, Button1, moveorplace, {.i = 0}},
    {ClkClientWin, MODKEY, Button2, togglefloating, {0}},
    {ClkClientWin, MODKEY, Button3, resizemouse, {0}},
    {ClkClientWin, ControlMask, Button1, dragmfact, {0}},
    {ClkClientWin, ControlMask, Button3, dragcfact, {0}},
    {ClkTagBar, 0, Button1, view, {0}},
    {ClkTagBar, 0, Button3, toggleview, {0}},
    {ClkTagBar, MODKEY, Button1, tag, {0}},
    {ClkTagBar, MODKEY, Button3, toggletag, {0}},
    {ClkTabBar, 0, Button1, focuswin, {0}},
    {ClkTabBar, 0, Button1, focuswin, {0}},
    {ClkTabPrev, 0, Button1, movestack, {.i = -1}},
    {ClkTabNext, 0, Button1, movestack, {.i = +1}},
    {ClkTabClose, 0, Button1, killclient, {0}},
};
