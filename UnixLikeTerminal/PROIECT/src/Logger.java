
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class Logger {
	public static final Logger instance = new Logger();
	static User user;
	
	public Logger()
	{
		
	}
	static List<User> users = new ArrayList<User>();
	
	public static User getUser()
	{
		return user;
	}
	
	public static final Logger getInstance( ) {
		return instance;
		 }
	public static void setUser(User u)
	{
		user = u;
	}
}
