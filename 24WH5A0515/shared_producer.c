# include < stdio .h >
# include < stdlib .h >
# include < sys / ipc .h >
# include < sys / shm .h >
# include < unistd .h >
# include < string .h >
# define SHM_SIZE 1024
struct shared_data {
  char message [ SHM_SIZE ];
  int available ;
};
int main () {
 key_t key = ftok (" shmfile ", 65) ;
 int shmid = shmget ( key , sizeof ( struct shared_data ) , 0666 | IPC_CREAT ) ;
 struct shared_data * data = ( struct shared_data *) shmat ( shmid ,NULL , 0) ;
 while (1) {
  printf (" Enter message to produce : ") ;
  fgets ( data - > message , SHM_SIZE , stdin ) ;
  data - > available = 1;
  while ( data - > available ) {
    usleep (100000) ;
   }
 }
 shmdt ( data ) ;
 return 0;
}
