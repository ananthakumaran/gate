#include "gate.h"
#include "erl_nif.h"

static ERL_NIF_TERM approxidate_nif(ErlNifEnv* env, int argc, const ERL_NIF_TERM argv[])
{
	unsigned int datestr_len;
	ERL_NIF_TERM date;
	char *datestr;
	unsigned long t;

	if(argc != 1 || !enif_is_list(env, argv[0]))
		return enif_make_badarg(env);

	date = argv[0];

	enif_get_list_length(env, date, &datestr_len);
	datestr = malloc(datestr_len + 1);
	enif_get_string(env, date, datestr, datestr_len + 1, ERL_NIF_LATIN1);
	t = approxidate(datestr);
	free(datestr);
	return enif_make_ulong(env, t);
}

// nif
static ErlNifFunc nif_funcs[] = {
	{"approxidate_nif", 1, approxidate_nif}
};

ERL_NIF_INIT(gate, nif_funcs, NULL, NULL, NULL, NULL);
