# include < stdio .h >
# include < stdlib .h >
# include < sys / ipc .h >
# include < sys / shm .h >
# include < unistd .h >
# define SHM_SIZE 1024
struct shared_data {
 char message [ SHM_SIZE ];
 int available ;
};
int main () {
 key_t key = ftok (" shmfile ", 65) ;
 int shmid = shmget ( key , sizeof ( struct shared_data ) , 0666 |IPC_CREAT ) ;
 struct shared_data * data = ( struct shared_data *) shmat ( shmid ,NULL , 0) ;
 while (1) {
   while (! data - > available ) {
      usleep (100000) ;
    }
    printf (" Consumed : %s", data - > message ) ;
    data - > available = 0;
  }
 shmdt ( data ) ;
 shmctl ( shmid , IPC_RMID , NULL ) ;
 return 0;
}
