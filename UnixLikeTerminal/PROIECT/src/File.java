import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;

public class File implements Repository{
	private String name;
	String size;
	String content ;
	String data;
	boolean read;
	boolean write;
	String user;
	
	public File(String name,String size,boolean read , boolean write, String user)
	{
		this.read = read;
		this.write = write;
		this.user = user;
		DateFormat format = new SimpleDateFormat("dd/MM/yy HH:mm:ss");
		Date dataCreare = new Date();
		this.data = "" + format.format(dataCreare);
		this.name = name ;
		this.size = size;
		this.content = "File test!\n";
	}
	


	public void accept(Command c) {
		c.execute2(this);
		
	}

	@Override
	public String getPath() {
		// TODO Auto-generated method stub
		return this.name;
	}

	@Override
	public String getContent(){
		return this.content;
	}



	@Override
	public boolean getPermisionRead() {
		// TODO Auto-generated method stub
		return false;
	}



	@Override
	public boolean getPermisionWrite() {
		// TODO Auto-generated method stub
		return false;
	}



	@Override
	public String getUser() {
		// TODO Auto-generated method stub
		return null;
	}



	@Override
	public Repository getChild(Repository i) {
		// TODO Auto-generated method stub
		return null;
	}
	

}
