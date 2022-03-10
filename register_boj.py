import argparse, os
if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('fileName')
    parser.add_argument('problemNum')
    args = parser.parse_args()
    ext = os.path.splitext(args.fileName)[1]
    try:
        os.mkdir('.\BOJ\milkclouds\%s' % args.problemNum)
    except: pass
    os.system('move %s .\BOJ\milkclouds\%s\%s%s' % (args.fileName, args.problemNum, args.problemNum, ext))
    