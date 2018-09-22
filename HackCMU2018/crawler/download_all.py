from github import Github
import wget
import os, requests
from datetime import datetime
def download():
    cwd = os.getcwd()
    g = Github("hackcmucrawler",'''%uAbPPe^@7U9''',per_page=100)
    sum_lines = 0
    num_files = 778
    repos = g.get_repos()
    for repo in repos:
        print(g.rate_limiting)
        try:
            if (not (repo.language == "C" or repo.language == "C++" or repo.language == "Cpp")):
                print("not C")
                continue
            print("C!")
            branches_objs = repo.get_branches()
            branches = [b.name for b in branches_objs]
            if "master" in branches:
                master_commit = repo.get_branch("master").commit
                master_commit_sha = master_commit.sha
                total_tree = repo.get_git_tree(master_commit_sha,recursive=True).tree
                cpp_files = [c for c in total_tree if ".cpp" in c.path or ".cc" in c.path]
                #print(cpp_files)
                if (len(cpp_files) > 0):
                    #contents = [repo.get_file_contents(c) for c in cpp_files]
                    for file in cpp_files:
                        file_name = str(file.path).replace("/","")
                        url = "https://raw.githubusercontent.com/" + str(repo.owner.login) + "/" + str(repo.name) + "/master/" + str(file.path)
                        output_path = os.path.join(cwd,os.path.join("cpp_files",file_name))
                        #If already downloaded, dont download
                        if (os.path.exists(output_path)):
                            print("Already downloaded")
                            continue
                        print(url)
                        r = requests.get(url,stream=True)
                        file_length = len([l for l in r.iter_lines()])
                        if (file_length < 50 or file_length > 2500):
                            break
                        wget.download(url, out=output_path)
                        sum_lines += file_length
                        num_files += 1
        except Exception as e:
            print(str(e))
    print("\n")
    print("Num files: " + str(num_files))
    print("\n")
    print("Average file line number: " + str(sum_lines / num_files))

if __name__ == "__main__":
    download()

def test():
    g = Github("hackcmucrawler",'''%uAbPPe^@7U9''')
    print(g.rate_limiting)
    print(datetime.fromtimestamp(g.rate_limiting_resettime))
