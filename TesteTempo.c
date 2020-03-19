void tempo(){
    clock_t start_time, end_time;

    start_time = clock();
    
    end_time = clock();
    printf( "Execution time was %lu seconds\n",
          (end_time - start_time) / CLOCKS_PER_SEC );
}
