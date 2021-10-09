import argparse, os
if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('fileName')
    parser.add_argument('problemNum')
    args = parser.parse_args()
    try:
        os.mkdir('.\BOJ\milkclouds\%s' % args.problemNum)
        os.system('move %s .\BOJ\milkclouds\%s\%s.cpp' % (args.fileName, args.problemNum, args.problemNum))
    except: pass
    