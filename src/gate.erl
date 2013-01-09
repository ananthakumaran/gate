-module(gate).

-export([init/0, approxidate/1]).
-on_load(init/0).

-compile([export_all]).

init() ->
    SoName = case code:priv_dir(?MODULE) of
                 {error, bad_name} ->
                     case filelib:is_dir(filename:join(["..", priv])) of
                         true ->
                             filename:join(["..", priv, ?MODULE]);
                         false ->
                             filename:join([priv, ?MODULE])
                     end;
                 Dir ->
                     filename:join(Dir, ?MODULE)
             end,
    (catch erlang:load_nif(SoName, 0)),
    case erlang:system_info(otp_release) of
        "R13B03" -> true;
        _ -> ok
    end.


approxidate_nif(_Date) ->
    "Nif library not loaded".

approxidate(Date) ->
    Timestamp = approxidate_nif(Date),
    timestamp_to_triple(Timestamp).

timestamp_to_triple(Timestamp) ->
    {Timestamp div 1000000, Timestamp rem 1000000, 0}.
