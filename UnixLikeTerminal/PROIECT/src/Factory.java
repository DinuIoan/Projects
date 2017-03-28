import java.util.Scanner;

import javax.swing.JTextArea;

public class Factory {
	public Command getCommand(String command)
	{
		String[] arr = command.split(" ");
		boolean read = false;
		boolean write = false;
		String User = Logger.user.username;
		
		if(command.contains("-r-"))
		{
			read = true;
			write = false;
			User = Logger.user.username;
		}
		else if(command.contains("-rw"))
		{
			read = true;
			write = true;
			User = Logger.user.username;
		}
		else if(command.contains("---"))
		{
			read = false;
			write = false;
			User = Logger.user.username;
		}
		else if(command.contains("-w-"))
		{
			read = false;
			write = true;
			User = Logger.user.username;
		}
		
		
		if(command.contains("mkdir"))
		{
			return new CMDmkdir(arr[1],read,write,User);
			
		}
		else if(command.contains("touch"))
		{
			if(arr.length == 3)
			{
				if(command.contains("---"))
					return new CMDtouch(arr[1],read,write,User);
				else if(command.contains("-r-"))
				return new CMDtouch(arr[1],read,write,User);
				else if(command.contains("-rw"))
				return new CMDtouch(arr[1],read,write,User);
				else if(command.contains("-w-"))
				return new CMDtouch(arr[1],read,write,User);
				else 
					return new CMDtouch(arr[1],arr[2]);
			}
			if(arr.length == 4)
				return new CMDtouch(arr[1],arr[2],read,write,User);
			if(arr.length == 2)
				return new CMDtouch(arr[1]);
		}
		else if(command.contains("newuser"))
		{
			return new CMDnewuser(arr[1],arr[2],arr[3],arr[4]);
		}
		else if(command.contains("echo"))
		{
			if(command.contains("-POO"))
			{
				new Jdialog("Echo",command.substring(5, (command.length()-4)));
			}
			
			return new CMDecho(command.substring(5));
		}
		else if(command.contains("ls"))
		{
			if(arr.length == 1)
			return new CMDls();
			if(arr.length == 2)
			{
				if(arr[1].equals("-r"))
					return new CMDls("-r");
			}
		}
		else if(command.contains("userinfo"))
		{
			return new CMDuserinfo();
		}
		else if(command.contains("login"))
		{
			return new CMDlogin(arr[1],arr[2]);
		}
		else if(command.contains("logout"))
		{
			return new CMDlogout();
		}
		else if(command.contains("cat"))
		{
			return new CMDcat(arr[1]);
		}
		
		return null;
		
		
	}
	
}
