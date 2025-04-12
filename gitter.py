import os
import subprocess
import random
import time


def is_git_repository():
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
        subprocess.run(["git", "add", file_path], check=True)

        commit_message = os.path.basename(file_path)
        subprocess.run(["git", "commit", "-m", commit_message], check=True)

        subprocess.run(["git", "push"], check=True)
        print(f"✅ Successfully pushed: {os.path.basename(file_path)}")

    except subprocess.CalledProcessError as e:
        print(f"❌ Error during Git operation: {e}")
    except Exception as e:
        print(f"⚠️ Unexpected error: {e}")


def get_unpushed_files(script_filename):
    try:
        result = subprocess.run(
            ["git", "status", "--porcelain"],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            check=True
        )
        output = result.stdout.decode().strip().splitlines()
    except subprocess.CalledProcessError as e:
        print(f"❌ Error checking git status: {e}")
        return []

    unpushed_files = []
    for line in output:
        if not line.strip():
            continue
        status, path = line[:2], line[3:]
        if os.path.basename(path) == script_filename:
            continue
        unpushed_files.append(path)

    return unpushed_files


def main(directory_path):
    script_filename = os.path.basename(__file__)
    sleep_times = []

    if not is_git_repository():
        print("❌ Error: This script must be run inside a Git repository.")
        return

    while True:
        unpushed_files = get_unpushed_files(script_filename)

        if not unpushed_files:
            print("✅ All files have been pushed. Exiting.")
            break

        random.shuffle(unpushed_files)

        for file_path in unpushed_files:
            git_add_commit_push(file_path)

            sleep_time = random.randint(1, 3)
            sleep_times.append(sleep_time)
            time.sleep(sleep_time)

    print("\n🕒 Sleep times:")
    for i, sleep_time in enumerate(sleep_times, start=1):
        print(f"{i}. {sleep_time} seconds")

    total_sleep_time = sum(sleep_times)
    print(f"\n⏱️ Total sleep time: {total_sleep_time} seconds")


if __name__ == "__main__":
    directory_path = os.getcwd()
    main(directory_path)
