/*
   Copyright (C) Cfengine AS

   This file is part of Cfengine 3 - written and maintained by Cfengine AS.

   This program is free software; you can redistribute it and/or modify it
   under the terms of the GNU General Public License as published by the
   Free Software Foundation; version 3.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA

  To the extent this program is licensed as part of the Enterprise
  versions of Cfengine, the applicable Commerical Open Source License
  (COSL) may apply to this file if you as a licensee so wish it. See
  included file COSL.txt.
*/

/*****************************************************************************/
/*                                                                           */
/* File: prototypes3.h                                                       */
/*                                                                           */
/* Created: Sun Aug  5 13:43:56 2007                                         */
/*                                                                           */
/*****************************************************************************/

#ifndef CFENGINE_PROTOTYPES3_H
#define CFENGINE_PROTOTYPES3_H

#include "compiler.h"

/* Versions */

const char *Version(void);
const char *NameVersion(void);

/* cflex.l */

int yylex (void);

/* cfparse.y */

void yyerror (const char *s);
int yyparse (void);

/* alloc.c */

#include "alloc.h"

/* agent.c */

int ScheduleAgentOperations(Bundle *bp);

/* agentdiagnostic.c */

void AgentDiagnostic(void);

/* alphalist.c */

void InitAlphaList(AlphaList *al);
int InAlphaList(AlphaList al,const char *string);
int MatchInAlphaList(AlphaList al,char *string);
void PrependAlphaList(AlphaList *al, const char *string);
void IdempPrependAlphaList(AlphaList *al, const char *string);
void ListAlphaList(FILE *fp,AlphaList al,char sep);
void DeleteAlphaList(AlphaList *al);
AlphaList *CopyAlphaListPointers(AlphaList *al,AlphaList *ap);

/* args.c */

int MapBodyArgs(char *scopeid,Rlist *give,Rlist *take);
Rlist *NewExpArgs(FnCall *fp, Promise *pp);
void ArgTemplate(FnCall *fp, const FnCallArg *argtemplate, Rlist *finalargs);
void DeleteExpArgs(Rlist *args);

/* assoc.c */

#include "assoc.h"

/* attributes.c */

Attributes GetEnvironmentsAttributes(Promise *pp);
struct CfEnvironments GetEnvironmentsConstraints(Promise *pp);
Attributes GetOutputsAttributes(Promise *pp);
Attributes GetServicesAttributes(Promise *pp);
struct CfServices GetServicesConstraints(Promise *pp);
Attributes GetFilesAttributes(Promise *pp);
Attributes GetReportsAttributes(Promise *pp);
Attributes GetExecAttributes(Promise *pp);
Attributes GetProcessAttributes(Promise *pp);
Attributes GetStorageAttributes(Promise *pp);
Attributes GetClassContextAttributes(Promise *pp);
Attributes GetTopicsAttributes(Promise *pp);
Attributes GetThingsAttributes(Promise *pp);
Attributes GetInferencesAttributes(Promise *pp);
Attributes GetOccurrenceAttributes(Promise *pp);
Attributes GetPackageAttributes(Promise *pp);
Attributes GetMeasurementAttributes(Promise *pp);
Attributes GetDatabaseAttributes(Promise *pp);

struct Packages GetPackageConstraints(Promise *pp);
struct ExecContain GetExecContainConstraints(Promise *pp);
struct Recursion GetRecursionConstraints(Promise *pp);
struct FileSelect GetSelectConstraints(Promise *pp);
struct FilePerms GetPermissionConstraints(Promise *pp);
struct TransactionContext GetTransactionConstraints(Promise *pp);
struct DefineClasses GetClassDefinitionConstraints(Promise *pp);
struct FileRename GetRenameConstraints(Promise *pp);
struct FileDelete GetDeleteConstraints(Promise *pp);
struct FileChange GetChangeMgtConstraints(Promise *pp);
struct FileCopy GetCopyConstraints(Promise *pp);
struct FileLink GetLinkConstraints(Promise *pp);
struct Context GetContextConstraints(Promise *pp);
struct ProcessSelect GetProcessFilterConstraints(Promise *pp);
struct ProcessCount GetMatchesConstraints(Promise *pp);
struct EditDefaults GetEditDefaults(Promise *pp);
Attributes GetMethodAttributes(Promise *pp);
Attributes GetInterfacesAttributes(Promise *pp);
Attributes GetInsertionAttributes(Promise *pp);
struct EditLocation GetLocationAttributes(Promise *pp);
Attributes GetDeletionAttributes(Promise *pp);
Attributes GetColumnAttributes(Promise *pp);
Attributes GetReplaceAttributes(Promise *pp);
struct EditRegion GetRegionConstraints(Promise *pp);
struct EditReplace GetReplaceConstraints(Promise *pp);
struct EditColumn GetColumnConstraints(Promise *pp);
struct TopicAssociation GetAssociationConstraints(Promise *pp);
struct StorageMount GetMountConstraints(Promise *pp);
struct StorageVolume GetVolumeConstraints(Promise *pp);
struct CfTcpIp GetTCPIPAttributes(Promise *pp);
struct Report GetReportConstraints(Promise *pp);
struct LineSelect GetInsertSelectConstraints(Promise *pp);
struct LineSelect GetDeleteSelectConstraints(Promise *pp);
struct Measurement GetMeasurementConstraint(Promise *pp);
Acl GetAclConstraints(Promise *pp);
struct CfDatabase GetDatabaseConstraints(Promise *pp);

/* bootstrap.c */

void CheckAutoBootstrap(void);
void SetPolicyServer(char *name);
void CreateFailSafe(char *name);
void SetDocRoot(char *name);

/* cfstream.c */

void CfFOut(char *filename,enum cfreport level,char *errstr,char *fmt, ...)
    FUNC_ATTR_FORMAT(printf, 4, 5);

void CfOut(enum cfreport level, const char *errstr, const char *fmt, ...)
    FUNC_ATTR_FORMAT(printf, 3, 4);

void cfPS(enum cfreport level,char status,char *errstr,Promise *pp,Attributes attr,char *fmt, ...)
    FUNC_ATTR_FORMAT(printf, 6, 7);

void CfFile(FILE *fp,char *fmt, ...)
    FUNC_ATTR_FORMAT(printf, 2, 3);

char *GetErrorStr(void);

/* cf_sql.c */

int CfConnectDB(CfdbConn *cfdb,enum cfdbtype dbtype,char *remotehost,char *dbuser, char *passwd, char *db);
void CfCloseDB(CfdbConn *cfdb);
void CfVoidQueryDB(CfdbConn *cfdb,char *query);
void CfNewQueryDB(CfdbConn *cfdb,char *query);
char **CfFetchRow(CfdbConn *cfdb);
char *CfFetchColumn(CfdbConn *cfdb,int col);
void CfDeleteQuery(CfdbConn *cfdb);

/* client_code.c */

void DetermineCfenginePort(void);
AgentConnection *NewServerConnection(Attributes attr,Promise *pp);
AgentConnection *ServerConnection(char *server,Attributes attr,Promise *pp);
void ServerDisconnection(AgentConnection *conn);
int cf_remote_stat(char *file,struct stat *buf,char *stattype,Attributes attr,Promise *pp);
void DeleteClientCache(Attributes attr,Promise *pp);
int CompareHashNet(char *file1,char *file2,Attributes attr,Promise *pp);
int CopyRegularFileNet(char *source,char *new,off_t size,Attributes attr,Promise *pp);
int EncryptCopyRegularFileNet(char *source,char *new,off_t size,Attributes attr,Promise *pp);
int ServerConnect(AgentConnection *conn,char *host,Attributes attr, Promise *pp);
void DestroyServerConnection(AgentConnection *conn);

/* Only for OpenDirForPromise implementation */
Dir *OpenDirRemote(const char *dirname,Attributes attr,Promise *pp);

/* Mark connection as free */
void ServerNotBusy(AgentConnection *conn);

/* Only for agent.c */

void ConnectionsInit(void);
void ConnectionsCleanup(void);

/* client_protocols.c */

int IdentifyAgent(int sd,char *localip,int family);
int AuthenticateAgent(AgentConnection *conn,Attributes attr,Promise *pp);
int BadProtoReply(char *buf);
int OKProtoReply(char *buf);
int FailedProtoReply(char *buf);


/* chflags.c */

int ParseFlagString (Rlist *flags, u_long *plusmask, u_long *minusmask);

/* communication.c */

AgentConnection *NewAgentConn(void);
void DeleteAgentConn(AgentConnection *ap);
void DePort(char *address);
int IsIPV6Address(char *name);
int IsIPV4Address(char *name);
const char *Hostname2IPString(const char *hostname);
char *IPString2Hostname(char *ipaddress);
int GetMyHostInfo(char nameBuf[MAXHOSTNAMELEN], char ipBuf[MAXIP4CHARLEN]);

/* comparray.c */

int FixCompressedArrayValue (int i, char *value, CompressedArray **start);
void DeleteCompressedArray (CompressedArray *start);
int CompressedArrayElementExists (CompressedArray *start, int key);
char *CompressedArrayValue (CompressedArray *start, int key);

#include "constraints.h"

/* conversion.c */

char *EscapeJson(char *s, char *out, int outSz);
char *EscapeRegex(char *s, char *out, int outSz);
char *EscapeQuotes(const char *s, char *out, int outSz);
char *MapAddress (char *addr);
void IPString2KeyDigest(char *ipv4,char *result);
enum cfhypervisors Str2Hypervisors(char *s);
enum cfenvironment_state Str2EnvState(char *s);
enum insert_match String2InsertMatch(char *s);
long Months2Seconds(int m);
enum cfinterval Str2Interval(char *s);
int SyslogPriority2Int(char *s);
enum cfdbtype Str2dbType(char *s);
char *Rlist2String(Rlist *list,char *sep);
int Signal2Int(char *s);
enum cfreport String2ReportLevel(char *typestr);
enum cfhashes String2HashType(char *typestr);
enum cfcomparison String2Comparison(char *s);
enum cflinktype String2LinkType(char *s);
enum cfdatatype Typename2Datatype(char *name);
enum cfdatatype GetControlDatatype(const char *varname, const BodySyntax *bp);
enum cfagenttype Agent2Type(char *name);
enum cfsbundle Type2Cfs(char *name);
enum representations String2Representation(char *s);
int GetBoolean(const char *val);
long Str2Int(const char *s);
long TimeCounter2Int(const char *s);
long TimeAbs2Int(char *s);
mode_t Str2Mode(char *s);
double Str2Double(const char *s);
void IntRange2Int(char *intrange,long *min,long *max,Promise *pp);
int Month2Int(char *string);
int MonthLen2Int(char *string, int len);
void TimeToDateStr(time_t t, char *outStr, int outStrSz);
const char *GetArg0(const char *execstr);
void CommPrefix(char *execstr,char *comm);
int NonEmptyLine(char *s);
int Day2Number(char *datestring);
void UtcShiftInterval(time_t t, char *out, int outSz);
enum action_policy Str2ActionPolicy(char *s);
enum version_cmp Str2PackageSelect(char *s);
enum package_actions Str2PackageAction(char *s);
enum cf_acl_method Str2AclMethod(char *string);
enum cf_acl_type Str2AclType(char *string);
enum cf_acl_inherit Str2AclInherit(char *string);
enum cf_srv_policy Str2ServicePolicy(char *string);
char *Dtype2Str(enum cfdatatype dtype);
char *Item2String(Item *ip);
int IsNumber(char *s);
int IsRealNumber(char *s);
enum cfd_menu String2Menu(const char *s);

#ifndef MINGW
UidList *Rlist2UidList(Rlist *uidnames, Promise *pp);
GidList *Rlist2GidList(Rlist *gidnames, Promise *pp);
uid_t Str2Uid(char *uidbuff,char *copy,Promise *pp);
gid_t Str2Gid(char *gidbuff,char *copy,Promise *pp);
#endif  /* NOT MINGW */

/* crypto.c */

void KeepKeyPromises(void);
void DebugBinOut(char *buffer,int len,char *com);
void RandomSeed (void);
void LoadSecretKeys (void);
int EncryptString (char type,char *in, char *out, unsigned char *key, int len);
int DecryptString (char type,char *in, char *out, unsigned char *key, int len);
RSA *HavePublicKey (char *username,char *ipaddress,char *digest);
RSA *HavePublicKeyByIP(char *username,char *ipaddress);
void SavePublicKey (char *username,char *ipaddress,char *digest,RSA *key);
int RemovePublicKeys(const char *hostname);

/* dbm_api.c */

int OpenDB(char *filename, CF_DB **dbp);
int CloseDB(CF_DB *dbp);
int ValueSizeDB(CF_DB *dbp, char *key);
int ReadComplexKeyDB(CF_DB *dbp, char *key, int keySz,void *dest, int destSz);
int RevealDB(CF_DB *dbp, char *key, void **result, int *rsize);
int WriteComplexKeyDB(CF_DB *dbp, char *key,int keySz, const void *src, int srcSz);
int DeleteComplexKeyDB(CF_DB *dbp, char *key, int size);
int NewDBCursor(CF_DB *dbp,CF_DBC **dbcp);
int NextDB(CF_DB *dbp,CF_DBC *dbcp,char **key,int *ksize,void **value,int *vsize);
int DeleteDBCursor(CF_DB *dbp,CF_DBC *dbcp);
int ReadDB(CF_DB *dbp, char *key, void *dest, int destSz);
int WriteDB(CF_DB *dbp, char *key, const void *src, int srcSz);
int DeleteDB(CF_DB *dbp, char *key);
void OpenDBTransaction(CF_DB *dbp);
void CommitDBTransaction(CF_DB *dbp);
void CloseAllDB(void);

/* dbm_berkely.c */

#ifdef BDB  // FIXME
int BDB_OpenDB(char *filename,DB **dbp);
int BDB_CloseDB(DB *dbp);
int BDB_ValueSizeDB(DB *dbp, char *key);
int BDB_ReadComplexKeyDB(DB *dbp,char *name,int keysize,void *ptr,int size);
int BDB_RevealDB(DB *dbp,char *name,void **result,int *rsize);
int BDB_WriteComplexKeyDB(DB *dbp,char *name,int keysize, const void *ptr,int size);
int BDB_DeleteComplexKeyDB(DB *dbp,char *name,int size);
int BDB_NewDBCursor(CF_DB *dbp,CF_DBC **dbcp);
int BDB_NextDB(CF_DB *dbp,CF_DBC *dbcp,char **key,int *ksize,void **value,int *vsize);
int BDB_DeleteDBCursor(CF_DB *dbp,CF_DBC *dbcp);
#endif

/* dbm_quick.c */

#ifdef QDB  // FIXME
int QDB_OpenDB(char *filename, CF_QDB **qdbp);
int QDB_CloseDB(CF_QDB *qdbp);
int QDB_ValueSizeDB(CF_QDB *qdbp, char *key);
int QDB_ReadComplexKeyDB(CF_QDB *qdbp, char *key, int keySz,void *dest, int destSz);
int QDB_RevealDB(CF_QDB *qdbp, char *key, void **result, int *rsize);
int QDB_WriteComplexKeyDB(CF_QDB *qdbp, char *key, int keySz, const void *src, int srcSz);
int QDB_DeleteComplexKeyDB(CF_QDB *qdbp, char *key, int size);
int QDB_NewDBCursor(CF_QDB *qdbp,CF_QDBC **qdbcp);
int QDB_NextDB(CF_QDB *qdbp,CF_QDBC *qdbcp,char **key,int *ksize,void **value,int *vsize);
int QDB_DeleteDBCursor(CF_QDB *qdbp,CF_QDBC *qdbcp);
#endif

/* dbm_tokyocab.c */

#ifdef TCDB
int TCDB_OpenDB(char *filename, CF_TCDB **hdbp);
int TCDB_CloseDB(CF_TCDB *hdbp);
int TCDB_ValueSizeDB(CF_TCDB *hdbp, char *key);
int TCDB_ReadComplexKeyDB(CF_TCDB *hdbp, char *key, int keySz,void *dest, int destSz);
int TCDB_RevealDB(CF_TCDB *hdbp, char *key, void **result, int *rsize);
int TCDB_WriteComplexKeyDB(CF_TCDB *hdbp, char *key, int keySz, const void *src, int srcSz);
int TCDB_DeleteComplexKeyDB(CF_TCDB *hdbp, char *key, int size);
int TCDB_NewDBCursor(CF_TCDB *hdbp,CF_TCDBC **hdbcp);
int TCDB_NextDB(CF_TCDB *hdbp,CF_TCDBC *hdbcp,char **key,int *ksize,void **value,int *vsize);
int TCDB_DeleteDBCursor(CF_TCDB *hdbp,CF_TCDBC *hdbcp);
#endif

/* dir.c */

Dir *OpenDirForPromise(const char *dirname, Attributes attr, Promise *pp);
Dir *OpenDirLocal(const char *dirname);
const struct dirent *ReadDir(Dir *dir);
void CloseDir(Dir *dir);

/* Only for OpenDirRemote implementation */
struct dirent *AllocateDirentForFilename(const char *filename);

/* dtypes.c */

int IsSocketType(char *s);
int IsTCPType(char *s);


/* enterprise_stubs.c */

void WebCache(char *s,char *t);
void EnterpriseModuleTrick(void);
int CheckDatabaseSanity(Attributes a, Promise *pp);
void VerifyRegistryPromise(Attributes a,Promise *pp);
int CfSessionKeySize(char c);
char CfEnterpriseOptions(void);
const EVP_CIPHER *CfengineCipher(char type);
void Aggregate(char *stylesheet,char *banner,char *footer,char *webdriver);
void SetPolicyServer(char *name);
int IsEnterprise(void);
void EnterpriseContext(void);
int EnterpriseExpiry(void);
const char *GetConsolePrefix(void);
const char *MailSubject(void);
void CheckAutoBootstrap(void);
void RegisterBundleDependence(char *absscope,Promise *pp);
void ShowTopicRepresentation(FILE *fp);
void PreSanitizePromise(Promise *pp);
void Nova_ShowTopicRepresentation(FILE *fp);
void NoteEfficiency(double e);
void HistoryUpdate(Averages newvals);
void GetObservable(int i, char *name, char *desc);
void LookupObservable(int i, char *name, char *desc);
void SummarizePromiseRepaired(int xml,int html,int csv,int embed,char *stylesheet,char *head,char *foot,char *web);
void SummarizePromiseNotKept(int xml,int html,int csv,int embed,char *stylesheet,char *head,char *foot,char *web);
void SummarizeCompliance(int xml,int html,int csv,int embed,char *stylesheet,char *head,char *foot,char *web);
void SummarizePerPromiseCompliance(int xml,int html,int csv,int embed,char *stylesheet,char *head,char *foot,char *web);
void SummarizeSetuid(int xml,int html,int csv,int embed,char *stylesheet,char *head,char *foot,char *web);
void SummarizeFileChanges(int xml,int html,int csv,int embed,char *stylesheet,char *head,char *foot,char *web);
void SummarizeValue(int xml,int html,int csv,int embed,char *stylesheet,char *head,char *foot,char *web);
void VerifyMeasurement(double *this,Attributes a,Promise *pp);
void SetMeasurementPromises(Item **classlist);
void LongHaul(time_t current);
void VerifyACL(char *file,Attributes a, Promise *pp);
int CheckACLSyntax(char *file,Acl acl,Promise *pp);
int VerifyTablePromise(CfdbConn *cfdb,char *name,Rlist *columns,Attributes a,Promise *pp);
void LogFileChange(char *file,int change,Attributes a,Promise *pp);
void RemoteSysLog(int log_priority, const char *log_string);
int VerifyDatabasePromise(CfdbConn *cfdb,char *database,Attributes a,Promise *pp);
int VerifyTablePromise(CfdbConn *cfdb,char *table,Rlist *columns,Attributes a,Promise *pp);
void ReportPatches(struct CfPackageManager *list);
void SummarizeSoftware(int xml,int html,int csv,int embed,char *stylesheet,char *head,char *foot,char *web);
void SummarizeUpdates(int xml,int html,int csv,int embed,char *stylesheet,char *head,char *foot,char *web);
void VerifyServices(Attributes a,Promise *pp);
void LoadSlowlyVaryingObservations(void);
void MonOtherInit(void);
void MonOtherGatherData(double *cf_this);
void RegisterLiteralServerData(char *handle,Promise *pp);
int ReturnLiteralData(char *handle,char *ret);
char *GetRemoteScalar(char *proto,char *handle,char *server,int encrypted,char *rcv);
const char *PromiseID(Promise *pp); /* Not thread-safe */
void NotePromiseCompliance(Promise *pp,double val,enum cf_status status,char *reasoin);
time_t GetPromiseCompliance(Promise *pp,double *value,double *average,double *var,time_t *lastseen);
void SyntaxCompletion(char *s);
int GetRegistryValue(char *key,char *name,char *buf, int bufSz);
void NoteVarUsage(void);
void NoteVarUsageDB(void);
void SummarizeVariables(int xml,int html,int csv,int embed,char *stylesheet,char *head,char *foot,char *web);
void CSV2XML(Rlist *list);
void *CfLDAPValue(char *uri,char *dn,char *filter,char *name,char *scope,char *sec);
void *CfLDAPList(char *uri,char *dn,char *filter,char *name,char *scope,char *sec);
void *CfLDAPArray(char *array,char *uri,char *dn,char *filter,char *scope,char *sec);
void *CfRegLDAP(char *uri,char *dn,char *filter,char *name,char *scope,char *regex,char *sec);
void CacheUnreliableValue(char *caller,char *handle,char *buffer);
int RetrieveUnreliableValue(char *caller,char *handle,char *buffer);
void TranslatePath(char *new,const char *old);
void GrandSummary(void);
void TrackValue(char *date,double kept,double repaired, double notkept);
void SetBundleOutputs(char *name);
void ResetBundleOutputs(char *name);
void SetPromiseOutputs(Promise *pp);
void VerifyOutputsPromise(Promise *pp);
void SpecialQuote(char *topic,char *type);
void LastSawBundle(char *name);
int GetInstalledPkgsRpath(struct CfPackageItem **pkgList, Attributes a, Promise *pp);
int ExecPackageCommandRpath(char *command,int verify,int setCmdClasses,Attributes a,Promise *pp);
void NewPromiser(Promise *pp);
void AnalyzePromiseConflicts(void);
void AddGoalsToDB(char *goal_patterns, char *goal_categories);

void SetSyslogHost(const char *host);
void SetSyslogPort(uint16_t port);

/* env_context.c */

/* - Parsing/evaluating expressions - */
void ValidateClassSyntax(const char *str);
bool IsDefinedClass(const char *class);
bool IsExcluded(const char *exception);

bool EvalProcessResult(const char *process_result, AlphaList *proc_attr);
bool EvalFileResult(const char *file_result, AlphaList *leaf_attr);

/* - Rest - */
int Abort(void);
void KeepClassContextPromise(Promise *pp);
void PushPrivateClassContext(void);
void PopPrivateClassContext(void);
void DeletePrivateClassContext(void);
void DeleteEntireHeap(void);
void NewPersistentContext(char *name,unsigned int ttl_minutes,enum statepolicy policy);
void DeletePersistentContext(char *name);
void LoadPersistentContext(void);
void AddEphemeralClasses(Rlist *classlist);
void NewClass(const char *oclass); /* Copies oclass */
void NewBundleClass(char *class,char *bundle);
Rlist *SplitContextExpression(char *context,Promise *pp);
void DeleteClass(char *class);
int VarClassExcluded(Promise *pp,char **classes);
void NewClassesFromString(char *classlist);
void NegateClassesFromString(char *class);
int IsHardClass (char *sp);
void SaveClassEnvironment(void);
void DeleteAllClasses(Rlist *list);
void AddAllClasses(Rlist *list,int persist,enum statepolicy policy);

#include "env_monitor.h"

/* evalfunction.c */

FnCallResult CallFunction(const FnCallType *function, FnCall *fp, Rlist *finalargs);
int FnNumArgs(const FnCallType *call_type);

void *CfReadFile(char *filename,int maxsize);
void ModuleProtocol(char *command,char *line,int print);

/* expand.c */

void ExpandPromise(enum cfagenttype ag,char *scopeid,Promise *pp,void *fnptr);
void ExpandPromiseAndDo(enum cfagenttype ag,char *scope,Promise *p,Rlist *scalarvars,Rlist *listvars,void (*fnptr)());
Rval ExpandDanglers(char *scope,Rval rval,Promise *pp);
void ScanRval(const char *scope, Rlist **los, Rlist **lol, Rval rval, Promise *pp);

int IsExpandable(const char *str);
int ExpandScalar(const char *string, char buffer[CF_EXPANDSIZE]);
Rval ExpandBundleReference(char *scopeid, Rval rval);
FnCall *ExpandFnCall(char *contextid,FnCall *f,int expandnaked);
Rval ExpandPrivateRval(char *contextid, Rval rval);
Rlist *ExpandList(char *scopeid,Rlist *list,int expandnaked);
Rval EvaluateFinalRval(char *scopeid, Rval rval,int forcelist,Promise *pp);
int IsNakedVar(char *str,char vtype);
void GetNaked(char *s1, char *s2);
void ConvergeVarHashPromise(char *scope,Promise *pp,int checkdup);
int ExpandPrivateScalar(const char *contextid, const char *string, char buffer[CF_EXPANDSIZE]);

/* exec_tool.c */

int IsExecutable(const char *file);
int ShellCommandReturnsZero(char *comm,int useshell);
int GetExecOutput(char *command,char *buffer,int useshell);
void ActAsDaemon(int preserve);
char *ShEscapeCommand(char *s);
char **ArgSplitCommand(const char *comm);
void ArgFree(char **args);

/* files_copy.c */

void *CopyFileSources(char *destination,Attributes attr,Promise *pp);
int CopyRegularFileDisk(char *source,char *new,Attributes attr,Promise *pp);
void CheckForFileHoles(struct stat *sstat,Promise *pp);
int FSWrite(char *new,int dd,char *buf,int towrite,int *last_write_made_hole,int n_read,Attributes attr,Promise *pp);

/* files_edit.c */

EditContext *NewEditContext(char *filename,Attributes a,Promise *pp);
void FinishEditContext(EditContext *ec,Attributes a,Promise *pp);
int LoadFileAsItemList(Item **liststart,char *file,Attributes a,Promise *pp);
int SaveItemListAsFile(Item *liststart,char *file,Attributes a,Promise *pp);
int AppendIfNoSuchLine(char *filename, char *line);

/* files_editline.c */

int ScheduleEditLineOperations(char *filename,Bundle *bp,Attributes a,Promise *pp);

/* files_links.c */

char VerifyLink(char *destination,char *source,Attributes attr,Promise *pp);
char VerifyAbsoluteLink(char *destination,char *source,Attributes attr,Promise *pp);
char VerifyRelativeLink(char *destination,char *source,Attributes attr,Promise *pp);
char VerifyHardLink(char *destination,char *source,Attributes attr,Promise *pp);
int KillGhostLink(char *name,Attributes attr,Promise *pp);
int MakeHardLink (char *from,char *to,Attributes attr,Promise *pp);
int ExpandLinks(char *dest,char *from,int level);

/* files_hashes.c */

int FileHashChanged(char *filename,unsigned char digest[EVP_MAX_MD_SIZE+1],int warnlevel,enum cfhashes type,Attributes attr,Promise *pp);
void PurgeHashes(char *file,Attributes attr,Promise *pp);
void DeleteHash(CF_DB *dbp,enum cfhashes type,char *name);
ChecksumValue *NewHashValue(unsigned char digest[EVP_MAX_MD_SIZE+1]);
int CompareFileHashes(char *file1,char *file2,struct stat *sstat,struct stat *dstat,Attributes attr,Promise *pp);
int CompareBinaryFiles(char *file1,char *file2,struct stat *sstat,struct stat *dstat,Attributes attr,Promise *pp);
void HashFile(char *filename,unsigned char digest[EVP_MAX_MD_SIZE+1],enum cfhashes type);
void HashString(char *buffer,int len,unsigned char digest[EVP_MAX_MD_SIZE+1],enum cfhashes type);
int HashesMatch(unsigned char digest1[EVP_MAX_MD_SIZE+1],unsigned char digest2[EVP_MAX_MD_SIZE+1],enum cfhashes type);
char *HashPrint(enum cfhashes type,unsigned char digest[EVP_MAX_MD_SIZE+1]);
char *HashPrintSafe(enum cfhashes type,unsigned char digest[EVP_MAX_MD_SIZE+1], char buffer[EVP_MAX_MD_SIZE*4]);
const char *FileHashName(enum cfhashes id);
void HashPubKey(RSA *key,unsigned char digest[EVP_MAX_MD_SIZE+1],enum cfhashes type);

/* files_interfaces.c */

void SourceSearchAndCopy(char *from,char *to,int maxrecurse,Attributes attr,Promise *pp);
void VerifyCopy(char *source,char *destination,Attributes attr,Promise *pp);
void LinkCopy(char *sourcefile,char *destfile,struct stat *sb,Attributes attr, Promise *pp);
int cfstat(const char *path, struct stat *buf);
int cf_stat(char *file,struct stat *buf,Attributes attr, Promise *pp);
int cf_lstat(char *file,struct stat *buf,Attributes attr, Promise *pp);
int CopyRegularFile(char *source,char *dest,struct stat sstat,struct stat dstat,Attributes attr, Promise *pp);
int CfReadLine(char *buff,int size,FILE *fp);
int cf_readlink(char *sourcefile,char *linkbuf,int buffsize,Attributes attr, Promise *pp);

/* files_names.c */

int IsNewerFileTree(char *dir,time_t reftime);
char *Titleize (char *str);
int DeEscapeQuotedString(const char *in, char *out);
int CompareCSVName(const char *s1, const char *s2);
int IsDir(char *path);
int EmptyString(char *s);
char *JoinPath(char *path, const char *leaf);
char *JoinSuffix(char *path,char *leaf);
int JoinMargin(char *path, const char *leaf, char **nextFree, int bufsize, int margin);
int StartJoin(char *path,char *leaf,int bufsize);
int Join(char *path, const char *leaf, int bufsize);
int JoinSilent(char *path, const char *leaf, int bufsize);
int EndJoin(char *path,char *leaf,int bufsize);
int IsAbsPath(char *path);
void AddSlash(char *str);
void DeleteSlash(char *str);
const char *LastFileSeparator(const char *str);
int ChopLastNode(char *str);
char *CanonifyName(const char *str);
void CanonifyNameInPlace(char *str);
char *CanonifyChar(const char *str,char ch);
const char *ReadLastNode(const char *str);
int CompressPath(char *dest,char *src);
void Chop(char *str);
void StripTrailingNewline(char *str);
char *ScanPastChars(char *scanpast, char *input);
bool IsStrIn(const char *str, const char **strs);
bool IsStrCaseIn(const char *str, const char **strs);
char **String2StringArray(char *str, char separator);
void FreeStringArray(char **strs);
int IsAbsoluteFileName(const char *f);
bool IsFileOutsideDefaultRepository(const char *f);
int RootDirLength(char *f);
int SubStrnCopyChr(char *to,char *from,int len,char sep);
int CountChar(char *string,char sp);
void ReplaceChar(char *in, char *out, int outSz, char from, char to);
void ReplaceTrailingChar(char *str, char from, char to);
void ReplaceTrailingStr(char *str, char *from, char to);
int ReplaceStr(char *in, char *out, int outSz, char* from, char *to);
const char *GetSoftwareCacheFilename(char *buffer);

#if defined HAVE_PTHREAD_H && (defined HAVE_LIBPTHREAD || defined BUILDTIN_GCC_THREAD)
void *ThreadUniqueName(pthread_t tid);
#endif  /* HAVE PTHREAD */

/* files_operators.c */

int VerifyFileLeaf(char *path,struct stat *sb,Attributes attr,Promise *pp);
int CfCreateFile(char *file,Promise *pp,Attributes attr);
FILE *CreateEmptyStream(void);
int ScheduleCopyOperation(char *destination,Attributes attr,Promise *pp);
int ScheduleLinkChildrenOperation(char *destination,char *source,int rec,Attributes attr,Promise *pp);
int ScheduleLinkOperation(char *destination,char *source,Attributes attr,Promise *pp);
int ScheduleEditOperation(char *filename,Attributes attr,Promise *pp);
struct FileCopy *NewFileCopy(Promise *pp);
void VerifyFileAttributes(char *file,struct stat *dstat,Attributes attr,Promise *pp);
void VerifyFileIntegrity(char *file,Attributes attr,Promise *pp);
int VerifyOwner(char *file,Promise *pp,Attributes attr,struct stat *statbuf);
void VerifyCopiedFileAttributes(char *file,struct stat *dstat,struct stat *sstat,Attributes attr,Promise *pp);
int MoveObstruction(char *from,Attributes attr,Promise *pp);
void TouchFile(char *path,struct stat *sb,Attributes attr,Promise *pp);
int MakeParentDirectory(char *parentandchild,int force);
void RotateFiles(char *name,int number);
void CreateEmptyFile(char *name);
void VerifyFileChanges(char *file,struct stat *sb,Attributes attr,Promise *pp);
#ifndef MINGW
UidList *MakeUidList(char *uidnames);
GidList *MakeGidList(char *gidnames);
void AddSimpleUidItem(UidList **uidlist,uid_t uid,char *uidname);
void AddSimpleGidItem(GidList **gidlist,gid_t gid,char *gidname);
#endif  /* NOT MINGW */
void LogHashChange(char *file);

/* files_properties.c */

int ConsiderFile(const char *nodename,char *path,Attributes attr,Promise *pp);
void SetSearchDevice(struct stat *sb,Promise *pp);
int DeviceBoundary(struct stat *sb,Promise *pp);

/* files_repository.c */

int ArchiveToRepository(char *file,Attributes attr,Promise *pp);

/* files_select.c */

int SelectLeaf(char *path,struct stat *sb,Attributes attr,Promise *pp);
int GetOwnerName(char *path, struct stat *lstatptr, char *owner, int ownerSz);

/* fncall.c */

int IsBuiltinFnCall(Rval rval);
FnCall *NewFnCall(char *name, Rlist *args);
FnCall *CopyFnCall(FnCall *f);
int PrintFnCall(char *buffer, int bufsize,FnCall *fp);
void DeleteFnCall(FnCall *fp);
void ShowFnCall(FILE *fout,FnCall *fp);
FnCallResult EvaluateFunctionCall(FnCall *fp,Promise *pp);
enum cfdatatype FunctionReturnType(const char *name);
const FnCallType *FindFunction(const char *name);
void SetFnCallReturnStatus(char *fname,int status,char *message);
void FnCallPrint(Writer *writer, FnCall *fp);

/* full_write.c */

int FullWrite(int desc, const char *ptr, size_t len);

#include "generic_agent.h"

/* granules.c  */

char *ConvTimeKey (char *str);
char *GenTimeKey (time_t now);
int GetTimeSlot(time_t here_and_now);
int GetShiftSlot(time_t here_and_now);
time_t GetShiftSlotStart(time_t t);

/* hashes.c */

/* - specific hashes - */

int RefHash(char *name);
int ElfHash(char *key);
int OatHash(const char *key);
int GetHash(const char *name);

/* - hashtable operations - */

AssocHashTable *HashInit(void);

/* Insert element if it does not exist in hash table. Returns false if element
   already exists in table or if table is full. */
bool HashInsertElement(AssocHashTable *hashtable, const char *element,
                       Rval rval, enum cfdatatype dtype);

/* Deletes element from hashtable, returning whether element was found */
bool HashDeleteElement(AssocHashTable *hashtable, const char *element);

/* Looks up element in hashtable, returns NULL if not found */
CfAssoc *HashLookupElement(AssocHashTable *hashtable, const char *element);

/* Copies all elements of old hash table to new one. */
void HashCopy(AssocHashTable *newhash, AssocHashTable *oldhash);

/* Clear whole hash table */
void HashClear(AssocHashTable *hashtable);

/* Destroy hash table */
void HashFree(AssocHashTable *hashtable);

/* HashToList */
void HashToList(Scope *sp, Rlist **list);

/* - hashtable iterator - */

/*
HashIterator i = HashIteratorInit(hashtable);
CfAssoc *assoc;
while ((assoc = HashIteratorNext(&i)))
   {
   // do something with assoc;
   }
// No cleanup is required
*/
HashIterator HashIteratorInit(AssocHashTable *hashtable);
CfAssoc *HashIteratorNext(HashIterator *iterator);

/* html.c */

void CfHtmlHeader(FILE *fp,char *title,char *css,char *webdriver,char *banner);
void CfHtmlFooter(FILE *fp,char *footer);
void CfHtmlTitle(FILE *fp,char *title);
int IsHtmlHeader(char *s);

/* item_lib.c */

void PrependFullItem(Item **liststart,char *itemstring,char *classes,int counter,time_t t);
void PurgeItemList(Item **list,char *name);
Item *ReturnItemIn(Item *list, const char *item);
Item *ReturnItemInClass(Item *list,char *item,char *classes);
Item *ReturnItemAtIndex(Item *list,int index);
int GetItemIndex(Item *list,char *item);
Item *EndOfList(Item *start);
int IsItemInRegion(char *item,Item *begin,Item *end,Attributes a,Promise *pp);
void PrependItemList(Item **liststart,char *itemstring);
int SelectItemMatching(Item *s,char *regex,Item *begin,Item *end,Item **match,Item **prev,char *fl);
int SelectNextItemMatching(char *regexp,Item *begin,Item *end,Item **match,Item **prev);
int SelectLastItemMatching(char *regexp,Item *begin,Item *end,Item **match,Item **prev);
void InsertAfter(Item **filestart,Item *ptr,char *string);
int NeighbourItemMatches(Item *start,Item *location,char *string,enum cfeditorder pos,Attributes a,Promise *pp);
int RawSaveItemList(Item *liststart, char *file);
Item *SplitStringAsItemList(char *string,char sep);
Item *SplitString(const char *string, char sep);
int DeleteItemGeneral (Item **filestart, char *string, enum matchtypes type);
int DeleteItemLiteral (Item **filestart, char *string);
int DeleteItemStarting (Item **list,char *string);
int DeleteItemNotStarting (Item **list,char *string);
int DeleteItemMatching (Item **list,char *string);
int DeleteItemNotMatching (Item **list,char *string);
int DeleteItemContaining (Item **list,char *string);
int DeleteItemNotContaining (Item **list,char *string);
int CompareToFile(Item *liststart,char *file,Attributes a,Promise *pp);
Item *String2List(char *string);
int ListLen (Item *list);
int ByteSizeList(const Item *list);
int IsItemIn (Item *list, const char *item);
int IsMatchItemIn(Item *list,char *item);
Item *ConcatLists (Item *list1, Item *list2);
void CopyList(Item **dest,Item *source);
int FuzzySetMatch(char *s1, char *s2);
int FuzzyMatchParse(char *item);
int FuzzyHostMatch(char *arg0, char *arg1,char *basename);
int FuzzyHostParse(char *arg1,char *arg2);
void IdempItemCount(Item **liststart, const char *itemstring, const char *classes);
Item *IdempPrependItem(Item **liststart, const char *itemstring, const char *classes);
Item *IdempPrependItemClass(Item **liststart,char *itemstring,char *classes);
Item *PrependItem(Item **liststart, const char *itemstring, const char *classes);
void AppendItem(Item **liststart, const char *itemstring, char *classes);
void DeleteItemList (Item *item);
void DeleteItem (Item **liststart, Item *item);
void DebugListItemList (Item *liststart);
Item *SplitStringAsItemList (char *string, char sep);
void IncrementItemListCounter (Item *ptr, char *string);
void SetItemListCounter (Item *ptr, char *string,int value);
Item *SortItemListNames(Item *list);
Item *SortItemListClasses(Item *list);
Item *SortItemListCounters(Item *list);
Item *SortItemListTimes(Item *list);
char *ItemList2CSV(Item *list);
int ItemListSize(Item *list);
int MatchRegion(char *chunk,Item *location,Item *begin,Item *end);
Item *DeleteRegion(Item **liststart,Item *begin,Item *end);

/* iteration.c */

Rlist *NewIterationContext(char *scopeid,Rlist *listvars);
void DeleteIterationContext(Rlist *lol);
int IncrementIterationContext(Rlist *iterators,int count);
int EndOfIteration(Rlist *iterator);
int NullIterators(Rlist *iterator);

/* instrumentation.c */

struct timespec BeginMeasure(void);
void EndMeasure(char *eventname,struct timespec start);
void EndMeasurePromise(struct timespec start,Promise *pp);
void NoteClassUsage(AlphaList list);
void LastSaw(char *username,char *ipaddress,unsigned char digest[EVP_MAX_MD_SIZE+1],enum roles role);
double GAverage(double anew,double aold,double p);
bool RemoveHostFromLastSeen(const char *hostname, char *hostkey);

/* install.c */

int RelevantBundle(char *agent,char *blocktype);
Bundle *AppendBundle(Bundle **start,char *name, char *type, Rlist *args);
Body *AppendBody(Body **start,char *name, char *type, Rlist *args);
SubType *AppendSubType(Bundle *bundle,char *typename);
Promise *AppendPromise(SubType *type,char *promiser, Rval promisee, char *classes,char *bundle,char *bundletype);
void DeleteBundles(Bundle *bp);
void DeleteBodies(Body *bp);

/* interfaces.c */

void VerifyInterfacePromise(char *vifdev,char *vaddress,char *vnetmask,char *vbroadcast);

/* keyring.c */

int HostKeyAddressUnknown(char *value);

/* logging.c */

void BeginAudit(void);
void EndAudit(void);
void ClassAuditLog(Promise *pp,Attributes attr,char *str,char status,char *error);
void PromiseLog(char *s);
void FatalError(char *s, ...) FUNC_ATTR_NORETURN
    FUNC_ATTR_FORMAT(printf, 1, 2);

void AuditStatusMessage(FILE*fp,char status);

/* manual.c */

void TexinfoManual(char *mandir);

/* matching.c */

bool ValidateRegEx(const char *regex);
int FullTextMatch (const char *regptr, const char *cmpptr);
char *ExtractFirstReference(const char *regexp, const char *teststring); /* Not thread-safe */
int BlockTextMatch (char *regexp,char *teststring,int *s,int *e);
int IsRegexItemIn(Item *list,char *regex);
int IsPathRegex(char *str);
int IsRegex(char *str);
int MatchRlistItem(Rlist *listofregex,const char *teststring);
void EscapeSpecialChars(char *str, char *strEsc, int strEscSz, char *noEsc);
char *EscapeChar(char *str, int strSz, char esc);
void AnchorRegex(char *regex, char *out, int outSz);
int MatchPolicy(char *needle,char *haystack,Attributes a,Promise *pp);

/* modes.c */

int ParseModeString (char *modestring, mode_t *plusmask, mode_t *minusmask);

/* net.c */

int SendTransaction (int sd, char *buffer,int len, char status);
int ReceiveTransaction (int sd, char *buffer,int *more);
int RecvSocketStream (int sd, char *buffer, int toget, int nothing);
int SendSocketStream (int sd, char *buffer, int toget, int flags);

/* nfs.c */

#ifndef MINGW
int LoadMountInfo(Rlist **list);
void DeleteMountInfo(Rlist *list);
int VerifyNotInFstab(char *name,Attributes a,Promise *pp);
int VerifyInFstab(char *name,Attributes a,Promise *pp);
int VerifyMount(char *name,Attributes a,Promise *pp);
int VerifyUnmount(char *name,Attributes a,Promise *pp);
void MountAll(void);
#endif  /* NOT MINGW */

/* ontology.c */

#include "ontology.h"

/* patches.c */

int IsPrivileged (void);
char *StrStr (char *s1,char *s2);
int StrnCmp (char *s1,char *s2,size_t n);
int cf_strcmp(const char *s1, const char *s2);
int cf_strncmp(const char *s1,const char *s2, size_t n);
char *cf_strcpy(char *s1, const char *s2);
char *cf_strncpy(char *s1, const char *s2, size_t n);
int cf_strlen(const char *s);
char *cf_strchr(const char *s, int c);
char *MapName(char *s);
char *MapNameForward(char *s);
char *cf_ctime(const time_t *timep);
char *cf_strtimestamp_local(const time_t time, char *buf);
char *cf_strtimestamp_utc(const time_t time, char *buf);
int cf_closesocket(int sd);
int cf_mkdir(const char *path, mode_t mode);
int cf_chmod(const char *path, mode_t mode);
int cf_rename(const char *oldpath, const char *newpath);
void OpenNetwork(void);
void CloseNetwork(void);
void CloseWmi(void);
int LinkOrCopy(const char *from, const char *to, int sym);

/* pipes.c */

FILE *cf_popen(char *command,char *type);
FILE *cf_popensetuid(char *command,char *type,uid_t uid,gid_t gid,char *chdirv,char *chrootv,int background);
FILE *cf_popen_sh(char *command,char *type);
FILE *cf_popen_shsetuid(char *command,char *type,uid_t uid,gid_t gid,char *chdirv,char *chrootv,int background);
int cf_pclose(FILE *pp);
int cf_pclose_def(FILE *pfp,Attributes a,Promise *pp);
int VerifyCommandRetcode(int retcode, int fallback, Attributes a, Promise *pp);

#ifndef MINGW
int cf_pwait(pid_t pid);
#endif  /* NOT MINGW */

/* processes_select.c */

int SelectProcess(char *procentry,char **names,int *start,int *end,Attributes a,Promise *pp);
bool IsProcessNameRunning(char *procNameRegex);


/* promises.c */

char *BodyName(Promise *pp);
Body *IsBody(Body *list,char *key);
Bundle *IsBundle(Bundle *list,char *key);
Promise *DeRefCopyPromise(char *scopeid,Promise *pp);
Promise *ExpandDeRefPromise(char *scopeid,Promise *pp);
Promise *CopyPromise(char *scopeid,Promise *pp);
void DeletePromise(Promise *pp);
void DeletePromises(Promise *pp);
void PromiseRef(enum cfreport level,Promise *pp);
Promise *NewPromise(char *typename,char *promiser);
void HashPromise(char *salt,Promise *pp,unsigned char digest[EVP_MAX_MD_SIZE+1],enum cfhashes type);
void DebugPromise(Promise *pp);

/* recursion.c */

int DepthSearch(char *name,struct stat *sb,int rlevel,Attributes attr,Promise *pp);
int SkipDirLinks(char *path,const char *lastnode,struct Recursion r);

/* reporting.c */

void ShowAllReservedWords(void);
void ShowContext(void);
void ShowPromises(Bundle *bundles,Body *bodies);
void ShowPromise(Promise *pp, int indent);
void ShowScopedVariables(void);
void SyntaxTree(void);
void ShowBody(Body *body,int ident);
void DebugBanner(char *s);
void ReportError(char *s);
void BannerSubType(char *bundlename,char *type,int p);
void BannerSubSubType(char *bundlename,char *type);
void Banner(char *s);
void ShowPromisesInReport(Bundle *bundles, Body *bodies);
void ShowPromiseInReport(const char *version, Promise* pp, int indent);

/* rlist.c */
#include "rlist.h"
/*
 * TODO: Need to find a nice general solution to these sorts of situations.
 */
int PrependListPackageItem(struct CfPackageItem **list,char *item,Attributes a,Promise *pp);
int PrependPackageItem(struct CfPackageItem **list, const char *name, const char *version, const char* arch, Attributes a, Promise *pp);

/* scope.c */

void SetScope(char *id);
void SetNewScope(char *id);
void NewScope(char *name);
void DeleteScope(char *name);
Scope *GetScope(const char *scope);
void CopyScope(char *new, char *old);
void DeleteAllScope(void);
void AugmentScope(char *scope,Rlist *lvals,Rlist *rvals);
void DeleteFromScope(char *scope,Rlist *args);
void PushThisScope(void);
void PopThisScope(void);
void ShowScope(char *);

/* selfdiagnostic.c */

void SelfDiagnostic(void);
void TestVariableScan(void);
void TestExpandPromise(void);
void TestExpandVariables(void);

/* server_transform.c */

void KeepControlPromises(void);
Auth *GetAuthPath(char *path,Auth *list);
void Summarize(void);

/* signals.c */

void HandleSignals(int signum);
void SelfTerminatePrelude(void);

/* string_lib.c */

#include "string_lib.h"

/* sockaddr.c */

/* Not thread-safe */
char *sockaddr_ntop (struct sockaddr *sa);

/* Thread-safe. Returns boolean success.
   It's up to caller to provide large enough addr. */
bool sockaddr_pton (int af,void *src, void *addr);

/* storage_tools.c */

off_t GetDiskUsage(char *file, enum cfsizes type);

/* syntax.c */
#include "syntax.h"

/* sysinfo.c */

void GetNameInfo3(void);
void CfGetInterfaceInfo(enum cfagenttype ag);
void Get3Environment(void);
void BuiltinClasses(void);
void OSClasses(void);
int IsInterfaceAddress(char *adr);
int GetCurrentUserName(char *userName, int userNameLen);
#ifndef MINGW
void Unix_GetInterfaceInfo(enum cfagenttype ag);
void Unix_FindV6InterfaceInfo(void);
#endif  /* NOT MINGW */
const char *GetWorkDir(void);

/* For unit tests */
void DetectDomainName(const char *orig_nodename);

/* transaction.c */

void SummarizeTransaction(Attributes attr,Promise *pp,char *logname);
struct CfLock AcquireLock(char *operand,char *host,time_t now,Attributes attr,Promise *pp, int ignoreProcesses);
void YieldCurrentLock(struct CfLock this);
void GetLockName(char *lockname,char *locktype,char *base,Rlist *params);
#if defined HAVE_PTHREAD_H && (defined HAVE_LIBPTHREAD || defined BUILDTIN_GCC_THREAD)
int ThreadLock(pthread_mutex_t *name);
int ThreadUnlock(pthread_mutex_t *name);
#else
#define ThreadLock(name) (1)
#define ThreadUnlock(name) (1)
#endif

void PurgeLocks(void);
int ShiftChange(void);

int WriteLock(char *lock);
CF_DB *OpenLock(void);
void CloseLock(CF_DB *dbp);

/* timeout.c */

void SetTimeOut(int timeout);
void TimeOut(void);
void SetReferenceTime(int setclasses);
void SetStartTime(int setclasses);

/* unix.c */

#ifndef MINGW
int Unix_GracefulTerminate(pid_t pid);
int Unix_GetCurrentUserName(char *userName, int userNameLen);
int Unix_ShellCommandReturnsZero(char *comm,int useshell);
int Unix_DoAllSignals(Item *siglist,Attributes a,Promise *pp);
int Unix_LoadProcessTable(Item **procdata);
void Unix_CreateEmptyFile(char *name);
int Unix_IsExecutable(const char *file);
char *Unix_GetErrorStr(void);
#endif  /* NOT MINGW */

/* vars.c */

void LoadSystemConstants(void);
void ForceScalar(char *lval,char *rval);
void NewScalar(const char *scope, const char *lval, const char *rval, enum cfdatatype dt);
void DeleteScalar(const char *scope, const char *lval);
void NewList(char *scope,char *lval,void *rval,enum cfdatatype dt);
enum cfdatatype GetVariable(const char *scope, const char *lval, Rval *returnv);
void DeleteVariable(char *scope,char *id);
bool StringContainsVar(const char *s, const char *v);
int DefinedVariable(char *name);
int IsCf3VarString(char *str);
int BooleanControl(const char *scope, const char *name);
const char *ExtractInnerCf3VarString(const char *str,char *substr);
const char *ExtractOuterCf3VarString(const char *str, char *substr);
int UnresolvedVariables(CfAssoc *ap,char rtype);
int UnresolvedArgs(Rlist *args);
int IsQualifiedVariable(char *var);
int IsCfList(char *type);
int AddVariableHash(const char *scope, const char *lval, Rval rval, enum cfdatatype dtype, const char *fname, int no);
void DeRefListsInHashtable(char *scope,Rlist *list,Rlist *reflist);

/* verify_databases.c */

void VerifyDatabasePromises(Promise *pp);

/* verify_environments.c */

void VerifyEnvironmentsPromise(Promise *pp);

/* verify_exec.c */

void VerifyExecPromise(Promise *pp);

/* verify_files.c */

void VerifyFilePromise(char *path,Promise *pp);

void LocateFilePromiserGroup(char *wildpath,Promise *pp,void (*fnptr)(char *path, Promise *ptr));
void *FindAndVerifyFilesPromises(Promise *pp);
int FileSanityChecks(char *path,Attributes a,Promise *pp);

/* verify_interfaces.c */

void VerifyInterface(Attributes a,Promise *pp);
void VerifyInterfacesPromise(Promise *pp);

/* verify_measurements.c */

void VerifyMeasurementPromise(double *this,Promise *pp);

/* verify_methods.c */

void VerifyMethodsPromise(Promise *pp);
int VerifyMethod(char *attrname,Attributes a,Promise *pp);

/* verify_packages.c */

void VerifyPackagesPromise(Promise *pp);
void ExecuteScheduledPackages(void);
void CleanScheduledPackages(void);

/* verify_processes.c */

void VerifyProcessesPromise(Promise *pp);
void VerifyProcesses(Attributes a, Promise *pp);
int LoadProcessTable(Item **procdata);
int DoAllSignals(Item *siglist,Attributes a,Promise *pp);
int GracefulTerminate(pid_t pid);
void GetProcessColumnNames(char *proc,char **names,int *start,int *end);


/* verify_services.c */

void VerifyServicesPromise(Promise *pp);

/* verify_storage.c */

void *FindAndVerifyStoragePromises(Promise *pp);
void VerifyStoragePromise(char *path,Promise *pp);

/* verify_reports.c */

void VerifyReportPromise(Promise *pp);

#endif
