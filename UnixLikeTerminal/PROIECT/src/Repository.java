
public interface Repository {
	public void accept(Command c);
	public String getPath();
	public String getUser();
	public boolean getPermisionRead();
	public boolean getPermisionWrite();
	public Repository getChild(Repository i);
	public String getContent();
	
}
		