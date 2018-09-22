from github import Github
import wget
import os
def download():
    cwd = os.getcwd()
    g = Github("b19d02337eabf1c7591b4f71cc4cdfebb7522587")
    for repo in g.get_repos():
        branches = [b.name for b in repo.get_branches()]
        try:
            if "master" in branches:
                master_commit = repo.get_branch("master").commit
                master_commit_sha = master_commit.sha
                total_tree = repo.get_git_tree(master_commit_sha,recursive=True).tree
                cpp_files = [c.path for c in total_tree if ".cpp" in c.path or ".cc" in c.path]
                print(cpp_files)
                if (len(cpp_files) > 0):
                    contents = [repo.get_file_contents(c) for c in cpp_files]
                    for file in contents:
                        output_path = os.path.join(cwd,os.path.join("cpp_files",file.name))
                        wget.download(file.download_url, out=output_path)
        except Exception as e:
            print(str(e))

if __name__ == "__main__":
    download()
