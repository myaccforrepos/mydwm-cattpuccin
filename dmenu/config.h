
/* See LICENSE file for copyright and license details. */
/* Default settings; can be overriden by command line. */

/* dmenu position */
static int topbar = 1;

/
static const char *fonts[] = {
	"JetBrains Mono:size=10"
};

/* Prompt displayed to the left of the input field */
static const char *prompt = NULL;


static const char *colors[SchemeLast][2] = {
	/*               fg          bg */
	[SchemeNorm] = { "#cdd6f4", "#1e1e2e" },
	[SchemeSel]  = { "#1e1e2e", "#b4befe" },
	[SchemeOut]  = { "#1e1e2e", "#94e2d5" },
};

/*
 * -l option
 *
 * 0 = normal horizontal dmenu
 *
 * Increase this if you want a vertical menu.
 */
static unsigned int lines = 0;

/*
 * Characters not considered part of a word while deleting words.
 */
static const char worddelimiters[] = " ";
