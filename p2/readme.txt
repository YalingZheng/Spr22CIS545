Please read the pdf file (Introduction and Project 1: Threads).  This pdf file was written by Ben Pfaff. 

Please log in to grail.eecs.csuohio.edu, and then ssh to spirit (or other machine), and copy the tar file under your local directory
execute 
$ tar xvf pintos.tar

And you will see the unzipped files and directories

Change corresponding file(s), such as devices/timer.c methods
timer_sleep
timer_interrupt

Design test cases to see the difference. 

--------------------------------------------------------------------------------------------
/* Sleeps for approximately TICKS timer ticks.  Interrupts must
   be turned on. */
void
timer_sleep (int64_t ticks)
{

  /* make sure interrupt is on */  

  /* Set 'timer_sleep' for current thread. */

  /* Disable interrupts to make insertion to sleeping thread list and blocking run atomically. */

  /* Insert thread to a list that contains all sleeping threads ordered by 'sleeping_ticks' 
  * for example, call insert_current_thread_to_sleeping_threads_list
  */

  /* Block currently running thread, switch it's 'status' to 'THREAD_BLOCKED'. */

  /* Set interrupt to previous interrupt level. */
}


* Timer interrupt handler. */
static void timer_interrupt (struct intr_frame *args UNUSED)
{
  // change ticks 

  // change the tick of every thread in the sleeping_threads_list

  /* Iterate over all sleeping threads, unblock every thread which finishes sleeping
     for the given duration and remove it out of sleeping threads list. 
     */
}
