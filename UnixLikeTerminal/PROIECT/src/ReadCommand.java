
public abstract class ReadCommand implements Command{
	@Override
	public void execute(Repository rep) {
		if(rep.getPermisionRead() == true)
		{
			rep.accept(this);
		}
		else if(rep.getUser() == "root")
		{
			rep.accept(this);
		}
		else if(rep.getUser() == Logger.user.username)
		{
			rep.accept(this);
		}
		else 
			Terminal.txtArea.append("<Esuat\n");
	
	}

	@Override
	public abstract void execute2(Folder folder);
	@Override
	public abstract void execute2(File file);

}
