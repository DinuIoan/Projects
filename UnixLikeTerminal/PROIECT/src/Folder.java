import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;



public class Folder implements Repository{
	String path;
	boolean read;
	boolean write;
	String User;
	String dimension;
	
	public Folder(String path,boolean read,boolean write, String user)
	{
		this.path = path + "/";
		this.read = read;
		this.write = write;
		this.User = user;
	}
	
	static List<Repository> folders = new ArrayList<Repository>();
	public void accept(Command o) {
		o.execute2(this);
	}
	
	public void add(Repository r)
	{
		
		folders.add(r);
		
	}
	public Repository getChild(Repository i)
	{
		Terminal.txtArea.append(i.getPath());	
		return i;
	}
	
	
	public String getPath()
	{
		return this.path;
	}

	@Override
	public boolean getPermisionRead() {
		return read;
	}

	@Override
	public String getContent() {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public boolean getPermisionWrite() {
		return write;
	}

	@Override
	public String getUser() {
		return this.User;
	}	
	
}
