import os
import subprocess
import random
import time


def is_git_repository():
    # Check if the current directory is a Git repository
    try:
        result = subprocess.run(
            ["git", "rev-parse", "--is-inside-work-tree"],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            check=True
        )
        return result.returncode == 0
    except subprocess.CalledProcessError:
        return False


def git_add_commit_push(file_path):
    try:
        # Stage the file
        subprocess.run(["git", "add", file_path], check=True)
        
        # Commit with the file name as the message
        commit_message = os.path.basename(file_path)
        subprocess.run(["git", "commit", "-m", commit_message], check=True)
        
        # Push changes
        subprocess.run(["git", "push"], check=True)
        print(f"Successfully pushed: {os.path.basename(file_path)}")
    except subprocess.CalledProcessError as e:
        print(f"Error during Git operation: {e}")
    except Exception as e:
        print(f"Unexpected error: {e}")


def get_unpushed_files(directory_path, script_filename):
    unpushed_files = []
    
    for root, _, files in os.walk(directory_path):
        for file in files:
            file_path = os.path.join(root, file)
            
            # Skip the script file
            if file == script_filename:
                continue
            
            try:
                status = subprocess.run(
                    ["git", "ls-files", "--error-unmatch", file_path],
                    stderr=subprocess.PIPE,
                    stdout=subprocess.PIPE
                )
                if status.returncode != 0:
                    unpushed_files.append(file_path)
            except subprocess.CalledProcessError as e:
                print(f"Error checking file status: {e}")
            except Exception as e:
                print(f"Unexpected error: {e}")

    return unpushed_files


def main(directory_path):
    script_filename = os.path.basename(__file__)  # Get the name of the script file
    sleep_times = []

    # Check if the current directory is a Git repository
    if not is_git_repository():
        print("Error: This script must be run inside a Git repository.")
        return

    while True:
        # Get a list of unpushed files excluding the script file
        unpushed_files = get_unpushed_files(directory_path, script_filename)

        if not unpushed_files:
            print("All files have been pushed. Exiting.")
            break

        # Shuffle the list to randomize the order
        random.shuffle(unpushed_files)

        for file_path in unpushed_files:
            git_add_commit_push(file_path)
            
            # Sleep for a random time between 1 and 3 seconds
            sleep_time = random.randint(1, 3)
            sleep_times.append(sleep_time)
            time.sleep(sleep_time)

    # Print sleep times and their total
    print("\nSleep times:")
    for i, sleep_time in enumerate(sleep_times, start=1):
        print(f"{i}. {sleep_time} seconds")

    total_sleep_time = sum(sleep_times)
    print(f"\nTotal sleep time: {total_sleep_time} seconds")


if __name__ == "__main__":
    directory_path = os.getcwd()  # Use the current working directory
    main(directory_path)
