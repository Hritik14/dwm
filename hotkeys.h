#include <X11/XF86keysym.h>

static const char scratchpadname[] = "notebook";
/* commands */
static const char
	*app_launcher[] = { "application-launcher", NULL },
	*termcmd[]  = { "termite", NULL },
	*lock[] = {"lock.sh", NULL},
	*filemanager[] = {"nautilus", NULL},
	*special_chars[] = {"special_characters.sh", NULL},
	*screencast[] = {"toggle.sh","ffmpeg_screencast", NULL},
	*clipbox[] = {"clipbox", NULL},
	*vanish[] = {"toggle.sh", "monitor", "eDP1", NULL},
	*take_break[] = {"safeeyes", "-t", NULL},
	*logkeys[] = {"toggle", "logkeys", NULL},
	*vol_up[] = {"volume", "inc", NULL},
	*vol_down[] = {"volume", "dec", NULL},
	*vol_toggle[] = {"volume", "toggle", NULL},
	*light_up[] = {"/usr/bin/light", "-A", "5", NULL},
	*light_down[] = {"/usr/bin/light", "-U", "5", NULL},
	*scratchpadcmd[] = { "termite", "-t", scratchpadname, "-e", "tmux", NULL };

// dunst
static const char
	*dunst_a0[] = {"/usr/bin/dunstctl","action","0", NULL},
	*dunst_a1[] = {"/usr/bin/dunstctl","action","1", NULL},
	*dunst_a2[] = {"/usr/bin/dunstctl","action","2", NULL},
	*dunst_c[] = {"/usr/bin/dunstctl","close",NULL},
	*dunst_ca[] = {"/usr/bin/dunstctl","close-all", NULL},
	*dunst_pop[] = {"/usr/bin/dunstctl","history-pop", NULL},
	*dunst_toggle[] = {"/usr/bin/dunstctl","set-paused","toggle", NULL};

static Key keys[] = {
	/* modifier                     key        function        argument */

	// Window management
	{ MODKEY,                       XK_p,      spawn,          {.v = app_launcher } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY, 			           	XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_r,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ShiftMask,             XK_r,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_g,      setlayout,      {.v = &layouts[5]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY, 		                XK_f,      fullscreen, 	   {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag, 	       {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ControlMask,             XK_BackSpace,      quit,           {0} },

	// custom keybindings
	{ WINKEY,			XK_l                    ,			spawn ,			{.v = lock}}         ,
	{ MODKEY,			XK_e                    ,			spawn ,			{.v = filemanager}}  ,
	{ MODKEY,			XK_s                    ,			spawn ,			{.v = special_chars}},
	{ 0     ,			XF86XK_AudioStop        ,			spawn ,			{.v = screencast}}   ,
	{ 0     ,			XF86XK_AudioPause       ,			spawn ,			{.v = take_break}}   ,
	{ MODKEY,			XK_u                    ,			spawn ,			{.v = clipbox}}      ,
	{ 0     ,			XK_F6                   ,			spawn ,			{.v = vanish}}       ,
	{ 0     ,			XK_F10                  ,			spawn ,			{.v = logkeys}}      ,
	{ 0     ,			XF86XK_AudioLowerVolume ,			spawn ,			{.v = vol_down}}     ,
	{ 0     ,			XF86XK_AudioRaiseVolume ,			spawn ,			{.v = vol_up}}       ,
	{ 0     ,			XF86XK_AudioMute        ,			spawn ,			{.v = vol_toggle}}   ,
	{ 0     ,			XF86XK_MonBrightnessUp  ,			spawn ,			{.v = light_up}}     ,
	{ 0     ,			XF86XK_MonBrightnessDown,			spawn ,			{.v = light_down}}   ,
	{ MODKEY,           XK_minus,  							togglescratch,  {.v = scratchpadcmd}},
	{ 0                    , XK_Print                , printscr , {.ui = 0}}                              ,
	{ ControlMask          , XK_Print, printscr , {.ui = ControlMask}}                    ,
	{ ShiftMask            , XK_Print, printscr , {.ui = ShiftMask}}                      ,
	{ ControlMask|ShiftMask, XK_Print, printscr , {.ui = ControlMask|ShiftMask}}          ,
	{ WINKEY               , XK_Print, printscr , {.ui = WINKEY}}                         ,
	{ WINKEY|ControlMask   , XK_Print, printscr , {.ui = WINKEY|ShiftMask|ControlMask}}   ,
		//dunst
	{ ControlMask       , XK_1    , spawn, {.v=dunst_a0} }    ,
	{ ControlMask       , XK_2    , spawn, {.v=dunst_a1} }    ,
	{ ControlMask       , XK_3    , spawn, {.v=dunst_a2} }    ,
	{ ControlMask       , XK_space, spawn, {.v=dunst_c} }     ,
	{ MODKEY|ControlMask, XK_space, spawn, {.v=dunst_ca} }    ,
	{ ControlMask       , XK_grave, spawn, {.v=dunst_pop} }   ,
	{ WINKEY            , XK_minus, spawn, {.v=dunst_toggle} },

};
