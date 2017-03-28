
public class CMDtouch extends WriteCommand{
	String numeFile;
	String dimension = ""+0;
	boolean read = false;
	boolean write = false;
	String User;

	
	public CMDtouch(String numeFile)
	{
		this.numeFile = numeFile;
	}	
	
	public CMDtouch(String numeFile, String dim)
	{
		this.numeFile = numeFile;
		this.dimension = dim;
	}
	
	public CMDtouch(String numeFile, String dim,boolean read,boolean write,String user)
	{
		this.numeFile = numeFile;
		this.dimension = dim;
		this.read = read;
		this.write = write;
		this.User = user;
	}
	public CMDtouch(String numeFile, boolean read,boolean write,String user)
	{
		this.numeFile = numeFile;
		this.read = read;
		this.write = write;
		this.User = user;
	}
	
	

	@Override
	public void execute2(Folder folder) {
		File f = new File(numeFile,dimension,read,write,User);
		folder.add(f);
		Terminal.txtArea.append("<Succes\n");
		
	}

	@Override
	public void execute2(File file) {
		Folder.folders.add(file);
		
	}
	
}
