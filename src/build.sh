echo "BUILDING LOGIC"
clang ./logic.c ./logic_symb.c ./logic_run.c ./logic_ops.c ./logic_karn.c -o ./logic
echo "LOGIC HAS BEEN BUILT - NOW WE GONNA RUN IT"
./logic