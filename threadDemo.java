//Practice code for JAVA multi-threading

class RunnableDemo implements Runnable {
// Dunno what Runnable code is, this is only learning

   private Thread t;
   private String threadName;

   RunnableDemo(String name){
	threadName = name
	System.out.println("Creating" + threadName);
   }

   public void run() {
	System.out.println("Running "+ threadName );
	try{
	   for (int i = 4; i>0; i--){
		System.out.println("Thread: " + threadName + ", " + i);
		Thread.sleep(50);
	   }
   } catch (InterruptedException e) {
	System.out.println("Thread " + threadName + " interrupted.");
   }
   System.out.println("Thread " + threadName + "exiting.");
   } 
 
   public void start () {
	System.out.println("Starting " + threadName );
	if (t == null) {
	    t = new Thread (this, threadName);
	    t.start();
	}
   }
}

public class TestThread {
   public static void main(Sting args[]){
	
	RunnableDemo R1 = new RunnableDemo( "Thread-1" );
	R1.start();

	RunnableDemo R2 = new RunnableDemo("Thread-2");
	R2.start();
   } 
}
