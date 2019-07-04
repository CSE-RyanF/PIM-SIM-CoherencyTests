#include "pim/pim_adder.hh"

PIMAdder::PIMAdder(const PIMAdder::Params *p):
PIMKernel(p)
{

}

PIMKernel::dataType
PIMAdder::doCompute(){
	
	computing_counts++;
	printf("Adding [0x%lu], [0x%lu], [0x%lu], [0x%lu], [0x%lu], [0x%lu], [0x%lu]", data[0], data[1],data[2],data[3],data[4],data[5],data[6]);
	return (dataType)(data[0]+data[1]+data[2]+data[3]+data[4]+data[5]+data[6]);
	//return r;
}
//Below is the function that tells pim to get all the surrounding pixel values and store them in the given registries
bool
PIMAdder::start(PacketPtr pkt){
    Packet::PIMSenderState* senderState = dynamic_cast<Packet::PIMSenderState*>(pkt->senderState);
    assert(senderState);
   // for(int i=0;i<senderState->addr.size();i++){
        regs[0].first=senderState->addr[0];
	//ifiok added this line
	DPRINTF(PIM, "BINGO!!!\n");
	DPRINTF(PIM, "Store Reg[%d] [0x%llx]\n",0,senderState->addr[0]);
        regs[0].second=dataReady;
	
	//arr0
	regs[1].first=regs[0].first + ((uint64_t) (8));
	//regs[1].first=senderState->addr[0];
	//ifiok added this line
	DPRINTF(PIM, "BINGO!!!\n");
	DPRINTF(PIM, "Store Reg[%d] [0x%llx]\n",1,((senderState->addr[0]) + (uint64_t) 8));
        regs[1].second=dataReady;

	//arr1
	regs[2].first=regs[0].first + ((uint64_t) (16));
	//regs[2].first=senderState->addr[0];
	//ifiok added this line
	DPRINTF(PIM, "BINGO!!!\n");
	DPRINTF(PIM, "Store Reg[%d] [0x%llx]\n",2,regs[0].first + ((uint64_t) (16)));
        regs[2].second=dataReady;

	//arr2
	regs[3].first=regs[0].first + ((uint64_t) (24));
	//regs[3].first=senderState->addr[0];
	//ifiok added this line
	DPRINTF(PIM, "BINGO!!!\n");
	DPRINTF(PIM, "Store Reg[%d] [0x%llx]\n",3,regs[0].first + ((uint64_t) (24)));
        regs[3].second=dataReady;

	//arr6
	regs[4].first=regs[0].first + ((uint64_t) (32));
	//regs[4].first=senderState->addr[0];
	//ifiok added this line
	DPRINTF(PIM, "BINGO!!!\n");
	DPRINTF(PIM, "Store Reg[%d] [0x%llx]\n",4,regs[0].first + ((uint64_t) (32)));
        regs[4].second=dataReady;

	//arr7
	regs[5].first=regs[0].first + ((uint64_t) (40));
	//regs[5].first=senderState->addr[0];
	//ifiok added this line
	DPRINTF(PIM, "BINGO!!!\n");
	DPRINTF(PIM, "Store Reg[%d] [0x%llx]\n",5,regs[0].first + ((uint64_t) (40)));
        regs[5].second=dataReady;

	//arr8
	regs[6].first=regs[0].first + ((uint64_t) (48));
	//regs[6].first=senderState->addr[0];
	//ifiok added this line
	DPRINTF(PIM, "BINGO!!!\n");
	DPRINTF(PIM, "Store Reg[%d] [0x%llx]\n",6,regs[0].first + ((uint64_t) (48)));
        regs[6].second=dataReady;	
	
	//in2
	regs[7].first=senderState->addr[1];
	//ifiok added this line
	DPRINTF(PIM, "BINGO!!!\n");
	DPRINTF(PIM, "Store Reg[%d] [0x%llx]\n",7,senderState->addr[1]);
        regs[7].second=dataReady;

	//out1
	regs[8].first=senderState->addr[2];
	//ifiok added this line
	DPRINTF(PIM, "BINGO!!!\n");
	DPRINTF(PIM, "Store Reg[%d] [0x%llx]\n",8,senderState->addr[2]);
        regs[8].second=dataReady;
    

    tickid=senderState->cycle;
    active();
    return true;
}

PIMAdder *
PIMAdderParams::create()
{
    return new PIMAdder(this);
}

