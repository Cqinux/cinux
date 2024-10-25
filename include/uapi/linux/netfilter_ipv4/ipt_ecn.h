/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
#ifndef _IPT_ECN_H
#define _IPT_ECN_H
#define _IPT_ECN_TARGET_H

#include <linux/netfilter/xt_ecn.h>
#define ipt_ecn_info xt_ecn_info

enum {
	IPT_ECN_IP_MASK       = XT_ECN_IP_MASK,
	IPT_ECN_OP_MATCH_IP   = XT_ECN_OP_MATCH_IP,
	IPT_ECN_OP_MATCH_ECE  = XT_ECN_OP_MATCH_ECE,
	IPT_ECN_OP_MATCH_CWR  = XT_ECN_OP_MATCH_CWR,
	IPT_ECN_OP_MATCH_MASK = XT_ECN_OP_MATCH_MASK,
};

#define IPT_ECN_IP_MASK	(~XT_DSCP_MASK)

#define IPT_ECN_OP_SET_IP	0x01	/* set ECN bits of IPv4 header */
#define IPT_ECN_OP_SET_ECE	0x10	/* set ECE bit of TCP header */
#define IPT_ECN_OP_SET_CWR	0x20	/* set CWR bit of TCP header */

#define IPT_ECN_OP_MASK		0xce

struct ipt_ECN_info {
	__u8 operation;	/* bitset of operations */
	__u8 ip_ect;	/* ECT codepoint of IPv4 header, pre-shifted */
	union {
		struct {
			__u8 ece:1, cwr:1; /* TCP ECT bits */
		} tcp;
	} proto;
};

#endif /* IPT_ECN_H */
