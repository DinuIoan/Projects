
public abstract class SystemCommand implements Command{
	public void execute(Repository rep){
		rep.accept(this);
	}
	public abstract void execute2(Folder folder);
	public abstract void execute2(File file);
}
