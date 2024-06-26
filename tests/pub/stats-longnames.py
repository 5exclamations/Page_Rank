import os
from common.utils import run, expect_stats


def run_test(sut, verbose, debug):
    this_dir = os.path.dirname(os.path.abspath(__file__))
    args = '-s ../graphs/longnames.dot'.split()

    proc, out = run(sut, args, this_dir, 3, verbose, debug)

    graphname = "LongGraphNamedurnfqajikjeorwzggdwkdgjmfhmifhrpwfhdbnxcpufnxuwyfousnmtcqhdabrcetvbijjkwkmlxhlarmyrrycqjcyenspxejbnpgrpdurtvtotgjgjsxevjlauqayqydalhspaliqcbhoczoezjqrctgtoabumdnqrdmelxsdlgkgdqnmryhmdgkkgazvzgewnzdvoqollrszoncmdltabzmbcsznmwojtdfgiwimodkflrez"
    expect_stats(proc, out, graphname, 10, 100, 6, 19, 7, 15, verbose, debug)


# More info about the graph:

# Minin: 6 at lmuesmbmlvdzyanbrzjfgnmjsfeerrlodwlpdiaycdaguoiopvthfcglopmanaiscegewipwzcuwkbbbfesgumeiutblexbbvfjmlcjreixjnqhmnqqfbetrrypiqjfnqmabzwmisyjygcqhmszckhgspsfiijcawymbaibljxnxcgkndmmvymtrppftcghfwynjshksuoiqpnijoepmaxeyrcxyjsecbvubtykfmnceqyxrtxsziipvfpnmitzi
# Maxin: 19 at vjjffmjnhpcmgvbzdrvjtwazgsjogejrdhvvygqwhcozzcdyypzuqoqfbfjlqluiiwbszdoslmjwtzvusuusyrbqcaozyfqncgmfhcpamcsbrisykyzriscaqzqovcgksgyrrnztbldmifsuvcqxkcrgyvkllldhjjsfwkmjiijwiwoayuckyyagddbkywaoxcaovmtlejzmrriwzaqijeuntwdlimjnmqenivoobbmxoqrhcfxrhndfourniquz
#
# Minout: 7 at lqkrhqtlatzytztayyhuifvjpkagyaunutbvkwrofecooipcndlkcgcygvcrvbdxwjzlixwfgrqtetsyrzirnujrwplsisjqfhgdrjccpxrrpmmgmfuztkwsbuqogjytnujhepdslibugrispdzeypewrlhsdjdwjpfdxlhqcsgjordyybzdsyrjtfzregzbvitbenycigtawltpipsrnmznmvkpuyqbdbcdmlodlmptemmedkysdnzuererwuhd
# Maxout: 15 at lmuesmbmlvdzyanbrzjfgnmjsfeerrlodwlpdiaycdaguoiopvthfcglopmanaiscegewipwzcuwkbbbfesgumeiutblexbbvfjmlcjreixjnqhmnqqfbetrrypiqjfnqmabzwmisyjygcqhmszckhgspsfiijcawymbaibljxnxcgkndmmvymtrppftcghfwynjshksuoiqpnijoepmaxeyrcxyjsecbvubtykfmnceqyxrtxsziipvfpnmitzi
